import { genRows } from '../genRows';
import { IColumns } from '../types';

describe('genRows', () => {
  it('generates rows', () => {
    const columns: IColumns[] = [
      {
        ana: 'ana.0',
        fac: 'fac.0',
        sol: 'sol.0',
        tot: 'tot.0',
        normAx: 'nax.0',
        relErr: 'rer.0',
      },
      {
        ana: 'ana.1',
        fac: 'fac.1',
        sol: 'sol.1',
        tot: 'tot.1',
        normAx: 'nax.1',
        relErr: 'rer.1',
      },
    ];
    const rows = genRows(columns);
    expect(rows).toMatchSnapshot();
  });
});
