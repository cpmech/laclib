import { genReadme } from '../genReadme';

describe('genReadme', () => {
  it('generates readme filw with bfwb62', () => {
    const readme = genReadme(['bfwb62']);
    expect(readme).toMatchSnapshot();
  });
});
