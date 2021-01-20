import { genColumns } from '../genColumns';
import { IReport, zeroReport } from '../types';

describe('genColumns', () => {
  it('generates columns', () => {
    const rpts: IReport[] = [zeroReport(), zeroReport()];

    rpts[0].StepAnalyze.ElapsedTimeString = 'ana.0';
    rpts[1].StepAnalyze.ElapsedTimeString = 'ana.1';

    rpts[0].StepFactorize.ElapsedTimeString = 'fac.0';
    rpts[1].StepFactorize.ElapsedTimeString = 'fac.1';

    rpts[0].StepSolve.ElapsedTimeString = 'sol.0';
    rpts[1].StepSolve.ElapsedTimeString = 'sol.1';

    rpts[0].TimeSolverString = 'tot.0';
    rpts[1].TimeSolverString = 'tot.1';

    rpts[0].Stats.NormInfAx = 1.23;
    rpts[1].Stats.NormInfAx = 1.45;

    rpts[0].Stats.RelativeError = 0.123;
    rpts[1].Stats.RelativeError = 0.456;

    const cols = genColumns(rpts, '');

    expect(cols.ana).toBe(`<td style="">ana.0</td>\n    <td style="">ana.1</td>`);
    expect(cols.fac).toBe(`<td style="">fac.0</td>\n    <td style="">fac.1</td>`);
    expect(cols.sol).toBe(`<td style="">sol.0</td>\n    <td style="">sol.1</td>`);
    expect(cols.tot).toBe(`<td style="">tot.0</td>\n    <td style="">tot.1</td>`);

    expect(cols.normAx).toBe(`<td style="">1.23</td>\n    <td style="">1.45</td>`);
    expect(cols.relErr).toBe(`<td style="">1.23e-1</td>\n    <td style="">4.56e-1</td>`);
  });
});
