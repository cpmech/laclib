export const genFnkey = (
  matrix: string,
  numPorT: number,
  intel: boolean = false,
  mpi: boolean = false,
  omp: boolean = false,
  solver: string = 'mumps',
  ordering: string = 'metis',
): string => {
  let plat = intel ? '_intel' : '_open';
  if (mpi) {
    plat += `_mpi${numPorT}`;
  } else {
    plat += `_seq`;
  }
  if (omp) {
    plat += `_omp${numPorT}`;
  }
  return `${solver}_${matrix}_${ordering}${plat}`;
};
