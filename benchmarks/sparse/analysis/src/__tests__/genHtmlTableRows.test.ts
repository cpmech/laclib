import { genHtmlTableRows } from '../genHtmlTableRows';
import { IHtmlColData } from '../types';

describe('genHtmlTableRows', () => {
  it('generates row data', () => {
    const columns: IHtmlColData[] = [
      {
        label: '',
        ana: 'ana.0',
        fac: 'fac.0',
        sol: 'sol.0',
        tot: 'tot.0',
        normAx: 'nax.0',
        relErr: 'rer.0',
      },
      {
        label: '',
        ana: 'ana.1',
        fac: 'fac.1',
        sol: 'sol.1',
        tot: 'tot.1',
        normAx: 'nax.1',
        relErr: 'rer.1',
      },
    ];
    const rows = genHtmlTableRows(columns, true);
    expect(rows).toMatchSnapshot();
  });
});
