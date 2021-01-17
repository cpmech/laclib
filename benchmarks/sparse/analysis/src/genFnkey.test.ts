import { genFnkey } from './genFnkey';

describe('genFnkey', () => {
  it('generates the filename key', () => {
    expect(genFnkey('mymat')).toBe('mumps_mymat_metis_mpi1');
  });
});
