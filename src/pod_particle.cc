#include "pod_particle.h"
namespace mpm {
namespace pod {
namespace particle {
const size_t dst_offset[NFIELDS] = {
    HOFFSET(PODParticle, id),
    HOFFSET(PODParticle, mass),
    HOFFSET(PODParticle, volume),
    HOFFSET(PODParticle, pressure),
    HOFFSET(PODParticle, coord_x),
    HOFFSET(PODParticle, coord_y),
    HOFFSET(PODParticle, coord_z),
    HOFFSET(PODParticle, displacement_x),
    HOFFSET(PODParticle, displacement_y),
    HOFFSET(PODParticle, displacement_z),
    HOFFSET(PODParticle, nsize_x),
    HOFFSET(PODParticle, nsize_y),
    HOFFSET(PODParticle, nsize_z),
    HOFFSET(PODParticle, velocity_x),
    HOFFSET(PODParticle, velocity_y),
    HOFFSET(PODParticle, velocity_z),
    HOFFSET(PODParticle, acceleration_x),
    HOFFSET(PODParticle, acceleration_y),
    HOFFSET(PODParticle, acceleration_z),
    HOFFSET(PODParticle, stress_xx),
    HOFFSET(PODParticle, stress_yy),
    HOFFSET(PODParticle, stress_zz),
    HOFFSET(PODParticle, tau_xy),
    HOFFSET(PODParticle, tau_yz),
    HOFFSET(PODParticle, tau_xz),
    HOFFSET(PODParticle, strain_xx),
    HOFFSET(PODParticle, strain_yy),
    HOFFSET(PODParticle, strain_zz),
    HOFFSET(PODParticle, gamma_xy),
    HOFFSET(PODParticle, gamma_yz),
    HOFFSET(PODParticle, gamma_xz),
    HOFFSET(PODParticle, defgrad_00),
    HOFFSET(PODParticle, defgrad_01),
    HOFFSET(PODParticle, defgrad_02),
    HOFFSET(PODParticle, defgrad_10),
    HOFFSET(PODParticle, defgrad_11),
    HOFFSET(PODParticle, defgrad_12),
    HOFFSET(PODParticle, defgrad_20),
    HOFFSET(PODParticle, defgrad_21),
    HOFFSET(PODParticle, defgrad_22),
    HOFFSET(PODParticle, status),
    HOFFSET(PODParticle, cell_id),
    HOFFSET(PODParticle, material_id),
    HOFFSET(PODParticle, nstate_vars),
    HOFFSET(PODParticle, svars[0]),
    HOFFSET(PODParticle, svars[1]),
    HOFFSET(PODParticle, svars[2]),
    HOFFSET(PODParticle, svars[3]),
    HOFFSET(PODParticle, svars[4]),
    HOFFSET(PODParticle, svars[5]),
    HOFFSET(PODParticle, svars[6]),
    HOFFSET(PODParticle, svars[7]),
    HOFFSET(PODParticle, svars[8]),
    HOFFSET(PODParticle, svars[9]),
    HOFFSET(PODParticle, svars[10]),
    HOFFSET(PODParticle, svars[11]),
    HOFFSET(PODParticle, svars[12]),
    HOFFSET(PODParticle, svars[13]),
    HOFFSET(PODParticle, svars[14]),
    HOFFSET(PODParticle, svars[15]),
    HOFFSET(PODParticle, svars[16]),
    HOFFSET(PODParticle, svars[17]),
    HOFFSET(PODParticle, svars[18]),
    HOFFSET(PODParticle, svars[19]),
};

// Get size of particle
PODParticle particle;
const size_t dst_sizes[NFIELDS] = {
    sizeof(particle.id),
    sizeof(particle.mass),
    sizeof(particle.volume),
    sizeof(particle.pressure),
    sizeof(particle.coord_x),
    sizeof(particle.coord_y),
    sizeof(particle.coord_z),
    sizeof(particle.displacement_x),
    sizeof(particle.displacement_y),
    sizeof(particle.displacement_z),
    sizeof(particle.nsize_x),
    sizeof(particle.nsize_y),
    sizeof(particle.nsize_z),
    sizeof(particle.velocity_x),
    sizeof(particle.velocity_y),
    sizeof(particle.velocity_z),
    sizeof(particle.acceleration_x),
    sizeof(particle.acceleration_y),
    sizeof(particle.acceleration_z),
    sizeof(particle.stress_xx),
    sizeof(particle.stress_yy),
    sizeof(particle.stress_zz),
    sizeof(particle.tau_xy),
    sizeof(particle.tau_yz),
    sizeof(particle.tau_xz),
    sizeof(particle.strain_xx),
    sizeof(particle.strain_yy),
    sizeof(particle.strain_zz),
    sizeof(particle.gamma_xy),
    sizeof(particle.gamma_yz),
    sizeof(particle.gamma_xz),
    sizeof(particle.defgrad_00),
    sizeof(particle.defgrad_01),
    sizeof(particle.defgrad_02),
    sizeof(particle.defgrad_10),
    sizeof(particle.defgrad_11),
    sizeof(particle.defgrad_12),
    sizeof(particle.defgrad_20),
    sizeof(particle.defgrad_21),
    sizeof(particle.defgrad_22),
    sizeof(particle.status),
    sizeof(particle.cell_id),
    sizeof(particle.material_id),
    sizeof(particle.nstate_vars),
    sizeof(particle.svars[0]),
    sizeof(particle.svars[1]),
    sizeof(particle.svars[2]),
    sizeof(particle.svars[3]),
    sizeof(particle.svars[4]),
    sizeof(particle.svars[5]),
    sizeof(particle.svars[6]),
    sizeof(particle.svars[7]),
    sizeof(particle.svars[8]),
    sizeof(particle.svars[9]),
    sizeof(particle.svars[10]),
    sizeof(particle.svars[11]),
    sizeof(particle.svars[12]),
    sizeof(particle.svars[13]),
    sizeof(particle.svars[14]),
    sizeof(particle.svars[15]),
    sizeof(particle.svars[16]),
    sizeof(particle.svars[17]),
    sizeof(particle.svars[18]),
    sizeof(particle.svars[19]),
};

// Define particle field information
const char* field_names[NFIELDS] = {
    "id",
    "mass",
    "volume",
    "pressure",
    "coord_x",
    "coord_y",
    "coord_z",
    "displacement_x",
    "displacement_y",
    "displacement_z",
    "nsize_x",
    "nsize_y",
    "nsize_z",
    "velocity_x",
    "velocity_y",
    "velocity_z",
    "acceleration_x",
    "acceleration_y",
    "acceleration_z",
    "stress_xx",
    "stress_yy",
    "stress_zz",
    "tau_xy",
    "tau_yz",
    "tau_xz",
    "strain_xx",
    "strain_yy",
    "strain_zz",
    "gamma_xy",
    "gamma_yz",
    "gamma_xz",
    "defgrad_00",
    "defgrad_01",
    "defgrad_02",
    "defgrad_10",
    "defgrad_11",
    "defgrad_12",
    "defgrad_20",
    "defgrad_21",
    "defgrad_22",
    "status",
    "cell_id",
    "material_id",
    "nstate_vars",
    "svars_0",
    "svars_1",
    "svars_2",
    "svars_3",
    "svars_4",
    "svars_5",
    "svars_6",
    "svars_7",
    "svars_8",
    "svars_9",
    "svars_10",
    "svars_11",
    "svars_12",
    "svars_13",
    "svars_14",
    "svars_15",
    "svars_16",
    "svars_17",
    "svars_18",
    "svars_19",
};

// Initialize field types
const hid_t field_type[NFIELDS] = {
    H5T_NATIVE_LLONG,  H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_HBOOL,  H5T_NATIVE_LLONG,  H5T_NATIVE_UINT,   H5T_NATIVE_UINT,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE,
    H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE, H5T_NATIVE_DOUBLE};
}  // namespace particle
}  // namespace pod
}  // namespace mpm
