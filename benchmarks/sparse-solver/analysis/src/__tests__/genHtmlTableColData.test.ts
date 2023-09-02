import { genHtmlTableColData } from '../genHtmlTableColData';
import { IReport, zeroReport } from '../types';

describe('genHtmlTAbleColData', () => {
  it('generates column data', () => {
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

    const cols = genHtmlTableColData('intel', { reports: rpts });

    expect(cols.Analyze).toBe(`<td>intel</td>\n    <td>ana.0</td>\n    <td>ana.1</td>`);
    expect(cols.Factorize).toBe(`<td>intel</td>\n    <td>fac.0</td>\n    <td>fac.1</td>`);
    expect(cols.Solve).toBe(`<td>intel</td>\n    <td>sol.0</td>\n    <td>sol.1</td>`);
    expect(cols.Total).toBe(`<td>intel</td>\n    <td>tot.0</td>\n    <td>tot.1</td>`);

    expect(cols['Norm(A.x)']).toBe(`<td>intel</td>\n    <td>1.23</td>\n    <td>1.45</td>`);
    expect(cols['Rel Error']).toBe(`<td>intel</td>\n    <td>1.23e-1</td>\n    <td>4.56e-1</td>`);
  });
});
