import { genReadme } from '../genReadme';

describe('genReadme', () => {
  it('generates readme filw with bfwb62', () => {
    const readme = genReadme(['bfwb62'], 'open_and_intel', [
      'seq_omp#',
      'mpi1_omp#',
      'mpi#',
      'mpi#_omp1',
      'mpi#_mpi#',
    ]);
    expect(readme).toMatchSnapshot();
  });
});
