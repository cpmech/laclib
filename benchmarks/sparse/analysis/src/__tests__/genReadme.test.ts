import marked from 'marked';
import DOMPurify from 'dompurify';
import { genReadme } from '../genReadme';
import { writeHtml } from '../genHtml';

describe('genReadme', () => {
  it('generates readme filw with bfwb62', () => {
    const readme = genReadme(['bfwb62'], 'open_and_intel', [
      'seq_omp#',
      'mpi1_omp#',
      'mpi#',
      'mpi#_omp1',
      'mpi#_omp#',
    ]);
    expect(readme).toMatchSnapshot();

    // debugging
    const htmlIn = marked(readme, { gfm: true });
    const htmlOut = DOMPurify.sanitize(htmlIn);
    const filepath = '/tmp/laclib/genReadme.test.html';
    writeHtml(filepath, 'laclib genReadme test', htmlOut);
    console.log(`file <${filepath}> written`);
  });
});
