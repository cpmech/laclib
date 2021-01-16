import { IReport } from './report';

const bcolor = '#979797';
const padding = '5px';
const styTable = `border: 1px solid ${bcolor}; border-collapse: collapse;`;
const styTheader = `border: 1px solid ${bcolor}; border-collapse: collapse; text-align: center; padding: ${padding};`;
const styLheader = `border: 1px solid ${bcolor}; border-collapse: collapse; text-align: right; padding: ${padding};`;
const styData = `border: 1px solid ${bcolor}; border-collapse: collapse; text-align: center; padding: ${padding};`;

export const genTable = (matrixName: string, r: IReport[], omp = false): string => {
  const h = omp ? 'OMP nt' : 'MPI np';
  return `<table style="${styTable}">
  <tr>
    <td style="${styTheader}">${matrixName}</td>
    <th style="${styTheader}">${h} 1</th>
    <th style="${styTheader}">${h} 2</th>
    <th style="${styTheader}">${h} 3</th>
    <th style="${styTheader}">${h} 4</th>
  </tr>
  <tr>
    <th style="${styLheader}">Analysis</th>
    <td style="${styData}">${r[0].StepAnalyze.ElapsedTimeString}</td>
    <td style="${styData}">${r[1].StepAnalyze.ElapsedTimeString}</td>
    <td style="${styData}">${r[2].StepAnalyze.ElapsedTimeString}</td>
    <td style="${styData}">${r[3].StepAnalyze.ElapsedTimeString}</td>
  </tr>
  <tr>
    <th style="${styLheader}">Factorize</th>
    <td style="${styData}">${r[0].StepFactorize.ElapsedTimeString}</td>
    <td style="${styData}">${r[1].StepFactorize.ElapsedTimeString}</td>
    <td style="${styData}">${r[2].StepFactorize.ElapsedTimeString}</td>
    <td style="${styData}">${r[3].StepFactorize.ElapsedTimeString}</td>
  </tr>
  <tr>
    <th style="${styLheader}">Solve</th>
    <td style="${styData}">${r[0].StepSolve.ElapsedTimeString}</td>
    <td style="${styData}">${r[1].StepSolve.ElapsedTimeString}</td>
    <td style="${styData}">${r[2].StepSolve.ElapsedTimeString}</td>
    <td style="${styData}">${r[3].StepSolve.ElapsedTimeString}</td>
  </tr>
  <tr>
    <th style="${styLheader}">Total</th>
    <td style="${styData}">${r[0].TimeSolverString}</td>
    <td style="${styData}">${r[1].TimeSolverString}</td>
    <td style="${styData}">${r[2].TimeSolverString}</td>
    <td style="${styData}">${r[3].TimeSolverString}</td>
  </tr>
</table>
`;
};
