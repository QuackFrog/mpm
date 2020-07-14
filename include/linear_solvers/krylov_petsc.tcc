//! Conjugate Gradient with default initial guess
template <typename Traits>
Eigen::VectorXd mpm::KrylovPETSC<Traits>::solve(
    const Eigen::SparseMatrix<double>& A, const Eigen::VectorXd& b,
    std::string solver_type) {
  //! Initialize solution vector x
  Eigen::VectorXd x(b.size());
  try {
#if USE_PETSC

    // Initialise MPI mpi_rank and size
    int mpi_rank = 0;
    int mpi_size = 1;

    // Get MPI mpi_rank
    MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
    // Get number of MPI mpi_ranks
    MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);

    // Initialize PETSC matrix, vectors, and parameters
    KSP solver;
    Mat petsc_A;
    Vec petsc_b, petsc_x;
    KSPConvergedReason reason;

    // Initialize vector b across the ranks
    VecCreateMPI(MPI_COMM_WORLD, PETSC_DECIDE, global_active_dof_, &petsc_b);
    VecDuplicate(petsc_b, &petsc_x);

    // Initialize Matrix A across the ranks
    MatCreateAIJ(MPI_COMM_WORLD, PETSC_DECIDE, PETSC_DECIDE, global_active_dof_,
                 global_active_dof_, 0, NULL, 0, NULL, &petsc_A);
    MatSetOption(petsc_A, MAT_NEW_NONZERO_ALLOCATION_ERR, PETSC_FALSE);

    // Copying Eigen vector b to petsc b vector
    VecSetValues(petsc_b, rank_global_mapper_.size(),
                 rank_global_mapper_.data(), b.data(), ADD_VALUES);
    VecAssemblyBegin(petsc_b);
    VecAssemblyEnd(petsc_b);

    // NOTE: Comment out to output assembled right-hand-side vector in each rank
    // PetscViewer viewer;
    // PetscViewerASCIIGetStdout(MPI_COMM_WORLD, &viewer);
    // VecView(petsc_b, viewer);

    // Copying Eigen matrix A to petsc A matrix
    for (int k = 0; k < A.outerSize(); ++k) {
      for (Eigen::SparseMatrix<double>::InnerIterator it(A, k); it; ++it) {
        MatSetValue(petsc_A, rank_global_mapper_[it.row()],
                    rank_global_mapper_[k], it.value(), ADD_VALUES);
      }
    }
    MatAssemblyBegin(petsc_A, MAT_FINAL_ASSEMBLY);
    MatAssemblyEnd(petsc_A, MAT_FINAL_ASSEMBLY);

    // NOTE: Comment out to output assembled coefficient matrix A
    // PetscViewer viewer;
    // PetscViewerASCIIGetStdout(MPI_COMM_WORLD, &viewer);
    // MatView(petsc_A, viewer);

    // Solve linear systems
    if (solver_type == "cg") {
      KSPCreate(MPI_COMM_WORLD, &solver);
      KSPSetOperators(solver, petsc_A, petsc_A);
      KSPSetType(solver, KSPCG);
      KSPSetTolerances(solver, tolerance_, PETSC_DEFAULT, PETSC_DEFAULT,
                       max_iter_);

      // NOTE: Comment out to add preconditioner settings
      // PC pc;
      // KSPCGSetType(solver, KSP_CG_SYMMETRIC);
      // KSPSetInitialGuessNonzero(solver, PETSC_TRUE);
      // KSPGetPC(solver, &pc);
      // PCFactorSetShiftType(pc, MAT_SHIFT_POSITIVE_DEFINITE);
      // PCSetType(pc, PCSOR);

      KSPSolve(solver, petsc_b, petsc_x);
      KSPGetConvergedReason(solver, &reason);

      // NOTE: Uncomment below to print residual in each iteration
      // PetscViewerAndFormat* vf;
      // PetscViewerAndFormatCreate(PETSC_VIEWER_STDOUT_WORLD,
      //                            PETSC_VIEWER_DEFAULT, &vf);
      // PetscInt its;
      // KSPGetIterationNumber(solver, &its);
      // PetscPrintf(PETSC_COMM_WORLD, "\nConvergence in %d iterations.\n",
      //             (int)its);
      // PetscReal rnorm;
      // for (int i = 0; i < its; i++) {
      //   KSPMonitorTrueResidualNorm(solver, i, rnorm, vf);
      // }
    }

    // Warn if solver does not converge
    if (reason < 0) {
      PetscPrintf(MPI_COMM_WORLD,
                  "\nKSPCG solver Diverged, try to modify the set tolerance "
                  "and maximum iteration.\n");
    }

    // Scatter and gather for cloning procedure
    if (mpi_size > 1) {
      // Initiate scatter arrays
      VecScatter ctx;
      Vec x_seq;
      PetscScalar* x_data;
      VecScatterCreateToAll(petsc_x, &ctx, &x_seq);
      VecScatterBegin(ctx, petsc_x, x_seq, INSERT_VALUES, SCATTER_FORWARD);
      VecScatterEnd(ctx, petsc_x, x_seq, INSERT_VALUES, SCATTER_FORWARD);
      VecGetArray(x_seq, &x_data);

      // Copy petsc x to Eigen x
      for (unsigned i = 0; i < x.size(); i++) {
        const int global_index = rank_global_mapper_[i];
        x(i) = x_data[global_index];
      }

      // Destroy scatter arrays
      VecRestoreArray(x_seq, &x_data);
      VecScatterDestroy(&ctx);
      VecDestroy(&x_seq);
    } else {
      PetscScalar value;
      // Copy petsc x to Eigen x
      for (unsigned i = 0; i < x.size(); i++) {
        const int global_index = rank_global_mapper_[i];
        VecGetValues(petsc_x, 1, &global_index, &value);
        x(i) = value;
      }
    }

#endif

  } catch (std::exception& exception) {
    console_->error("{} #{}: {}\n", __FILE__, __LINE__, exception.what());
  }

  return x;
}