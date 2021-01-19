export const genFnkey = (
  matrix: string,
  hasMpi: boolean,
  hasOmp: boolean,
  mpiNp: number,
  ompNt: number,
  intel: boolean = false,
  ordering: string = 'metis',
  solver: string = 'mumps',
): string => {
  let plat = intel ? '_intel' : '_open';
  if (hasMpi) {
    plat += `_mpi${mpiNp}`;
  } else {
    plat += `_seq`;
  }
  if (hasOmp) {
    plat += `_omp${ompNt}`;
  }
  return `${solver}_${matrix}_${ordering}${plat}`;
};

export const genFnkeysXor = (matrix: string, ompXorMpi = false, intel = false): string[] => {
  const hasMpi = !ompXorMpi;
  const hasOmp = ompXorMpi;
  return [1, 2, 3, 4].map((n) => {
    const mpiNp = hasMpi ? n : 0;
    const ompNt = hasOmp ? n : 0;
    return genFnkey(matrix, hasMpi, hasOmp, mpiNp, ompNt, intel);
  });
};
