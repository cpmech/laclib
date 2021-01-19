import { genFnkey, genFnkeysXor } from '../genFnkey';

describe('genFnkey', () => {
  it('generates the filename key', () => {
    expect(genFnkey('mymat', false, false, 0, 0)).toBe('mumps_mymat_metis_open_seq');
    expect(genFnkey('mymat', false, true, 0, 2)).toBe('mumps_mymat_metis_open_seq_omp2');
    expect(genFnkey('mymat', true, false, 3, 0)).toBe('mumps_mymat_metis_open_mpi3');
    expect(genFnkey('mymat', true, true, 4, 2)).toBe('mumps_mymat_metis_open_mpi4_omp2');

    expect(genFnkey('mymat', false, false, 0, 0, true)).toBe('mumps_mymat_metis_intel_seq');
    expect(genFnkey('mymat', false, true, 0, 2, true)).toBe('mumps_mymat_metis_intel_seq_omp2');
    expect(genFnkey('mymat', true, false, 3, 0, true)).toBe('mumps_mymat_metis_intel_mpi3');
    expect(genFnkey('mymat', true, true, 4, 2, true)).toBe('mumps_mymat_metis_intel_mpi4_omp2');
  });
});

describe('genFnkeysXor', () => {
  it('generates a bunch of filename keys', () => {
    expect(genFnkeysXor('mymat')).toEqual([
      'mumps_mymat_metis_open_mpi1',
      'mumps_mymat_metis_open_mpi2',
      'mumps_mymat_metis_open_mpi3',
      'mumps_mymat_metis_open_mpi4',
    ]);
    expect(genFnkeysXor('mymat', true)).toEqual([
      'mumps_mymat_metis_open_seq_omp1',
      'mumps_mymat_metis_open_seq_omp2',
      'mumps_mymat_metis_open_seq_omp3',
      'mumps_mymat_metis_open_seq_omp4',
    ]);
    expect(genFnkeysXor('mymat', false, true)).toEqual([
      'mumps_mymat_metis_intel_mpi1',
      'mumps_mymat_metis_intel_mpi2',
      'mumps_mymat_metis_intel_mpi3',
      'mumps_mymat_metis_intel_mpi4',
    ]);
    expect(genFnkeysXor('mymat', true, true)).toEqual([
      'mumps_mymat_metis_intel_seq_omp1',
      'mumps_mymat_metis_intel_seq_omp2',
      'mumps_mymat_metis_intel_seq_omp3',
      'mumps_mymat_metis_intel_seq_omp4',
    ]);
  });
});
