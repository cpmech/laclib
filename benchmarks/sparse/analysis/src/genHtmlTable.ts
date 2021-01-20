import { IReportSet } from './types';
import { genHtmlTableColData } from './genHtmlTableColData';
import { styTable, styTabHeader } from './htmlStyles';
import { genHtmlTableRows } from './genHtmlTableRows';

// example of reportSet:
//  "open"  : [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
//  "intel" : [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
export const genHtmlTable = (
  matrixName: string,
  reportSet: IReportSet,
  withLinfAx = false,
): string => {
  const labels = Object.keys(reportSet);
  const data = labels.map((label) => genHtmlTableColData(label, reportSet[label]));
  const rows = genHtmlTableRows(data, withLinfAx);

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
