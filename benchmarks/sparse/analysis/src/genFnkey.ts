export const genFnkey = (
  matrixName: string,
  mpiSize: number = 1,
  ompNumThreads: number = 0,
  intel: boolean = false,
  solverKind: string = 'mumps',
  ordering: string = 'metis',
): string => {
  const pfx = intel ? 'intel_' : '';
  const sfx = ompNumThreads > 0 ? `_omp${ompNumThreads}` : `_mpi${mpiSize}`;
  return `${pfx}${solverKind}_${matrixName}_${ordering}${sfx}`;
};
