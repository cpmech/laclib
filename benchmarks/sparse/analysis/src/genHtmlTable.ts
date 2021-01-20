import { IReportSet } from './types';
import { genHtmlTableColData } from './genHtmlTableColData';
import { styTable, styTabHeader, styTabLHeader } from './htmlStyles';

// example of reportSet:
//  "open"  : [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
//  "intel" : [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
export const genHtmlTable = (matrixName: string, reportSet: IReportSet): string => {
  const labels = Object.keys(reportSet);
  const data = labels.map((label) => genHtmlTableColData(label, reportSet[label]));

  const numOfLabels = labels.length;
  const rowspan = numOfLabels > 1 ? ` rowspan="${numOfLabels}"` : '';

  const tr0 = `\n  <tr>\n`;
  const trx = `\n  </tr>`;

  const th = (i: number, label: string, cols: string) =>
    i === 0
      ? `    <th style="${styTabLHeader}"${rowspan}>${label}</th>\n    ${cols}`
      : `    ${cols}`;

  const ana = data.map((c, i) => `${tr0}${th(i, 'Analyze', c.ana)}${trx}`);
  const fac = data.map((c, i) => `${tr0}${th(i, 'Factorize', c.fac)}${trx}`);
  const sol = data.map((c, i) => `${tr0}${th(i, 'Solve', c.sol)}${trx}`);
  const tot = data.map((c, i) => `${tr0}${th(i, 'Total', c.tot)}${trx}`);
  const rer = data.map((c, i) => `${tr0}${th(i, 'Rel Error', c.relErr)}${trx}`);

  const rows = ana.join('') + fac.join('') + sol.join('') + tot.join('') + rer.join('');

  const width = reportSet[labels[0]].length;
  const nums = Array.from(Array(width).keys());
  const lines = nums.map((i) => `<th style="${styTabHeader}">NP or NT ${i + 1}</th>`);
  const heads = lines.join(`\n    `);

  return `<table style="${styTable}">
  <tr>
    <td style="${styTabHeader}">${matrixName}</td>
    ${heads}
  </tr>${rows}
</table>
`;
};
