import { genReadme } from '../genReadme';
import { genHtml } from '../genHtml';

describe('genReadme', () => {
  it('generates readme filw with bfwb62', () => {
    const readme = genReadme(
      ['bfwb62'],
      ['open', 'intel'],
      ['seq_omp#', 'mpi1_omp#', 'mpi#', 'mpi#_omp1', 'mpi#_omp#'],
    );
    expect(readme).toMatchSnapshot();

    // debugging
    const filepath = '/tmp/laclib/genReadme.test.html';
    genHtml(filepath, 'laclib genReadme test', readme, true);
    console.log(`file <${filepath}> written`);
  });
});
