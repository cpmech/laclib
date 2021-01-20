import { IReportSet } from './types';
import { genHtmlTableColData } from './genHtmlTableColData';
import { styTable, styTabHeader, styTabLHeader } from './htmlStyles';

// example of reportSet:
//  "open"  : [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
//  "intel" : [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
export const genHtmlTable = (matrixName: string, reportSet: IReportSet): string => {
  // extract labels and data
  const labels = Object.keys(reportSet);
  const data = labels.map((label) => genHtmlTableColData(label, reportSet[label]));

  // auxiliary
  const numOfLabels = labels.length;
  const rowspan = numOfLabels > 1 ? ` rowspan="${numOfLabels}"` : '';

  // open and close table row
  const tr0 = `\n  <tr>\n`;
  const trx = `\n  </tr>`;

  // the header corresponding to the first label (l=0) gets multiple rowspan
  const th = (l: number, label: string, cols: string) =>
    l === 0
      ? `    <th style="${styTabLHeader}"${rowspan}>${label}</th>\n    ${cols}`
      : `    ${cols}`;

  // looping over labels
  const ana = data.map((d, l) => `${tr0}${th(l, 'Analyze', d.ana)}${trx}`);
  const fac = data.map((d, l) => `${tr0}${th(l, 'Factorize', d.fac)}${trx}`);
  const sol = data.map((d, l) => `${tr0}${th(l, 'Solve', d.sol)}${trx}`);
  const tot = data.map((d, l) => `${tr0}${th(l, 'Total', d.tot)}${trx}`);
  const rer = data.map((d, l) => `${tr0}${th(l, 'Rel Error', d.relErr)}${trx}`);

  // content of table: <tr>...</tr>
  const content = ana.join('') + fac.join('') + sol.join('') + tot.join('') + rer.join('');

  // header
  const nproc = reportSet[labels[0]].length;
  const nums = Array.from(Array(nproc).keys());
  const lines = nums.map((i) => `<th style="${styTabHeader}">NP or NT ${i + 1}</th>`);
  const heads = lines.join(`\n    `);

  // table
  return `<table style="${styTable}">
  <tr>
    <td style="${styTabHeader}">${matrixName}</td>
    ${heads}
  </tr>${content}
</table>
`;
};
