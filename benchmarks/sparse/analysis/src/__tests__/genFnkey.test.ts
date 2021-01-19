import { genFnkey } from '../genFnkey';

describe('genFnkey', () => {
  it('generates the filename key with', () => {
    expect(genFnkey('mymat', 1)).toBe('mumps_mymat_metis_open_seq');
    expect(genFnkey('mymat', 1, true)).toBe('mumps_mymat_metis_intel_seq');
    expect(genFnkey('mymat', 2, true, true)).toBe('mumps_mymat_metis_intel_mpi2');
    expect(genFnkey('mymat', 3, false, false, true)).toBe('mumps_mymat_metis_open_seq_omp3');
  });
});
