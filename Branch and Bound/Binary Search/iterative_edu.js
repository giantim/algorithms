// import visualization libraries {
const { Tracer, Array1DTracer, ChartTracer, LogTracer, Randomize, Layout, VerticalLayout } = require('algorithm-visualizer');
// }

const arySize = /* 배열의 길이를 입력 */; 
const intRange = /* 배열에 포함될 정수의 범위를 입력 */; 

// 시각화 {
const chart = new ChartTracer();
const tracer = new Array1DTracer();
const logger = new LogTracer();
Layout.setRoot(new VerticalLayout([chart, tracer, logger]));
const D = new Randomize.Array1D(arySize, new Randomize.Integer(0, intRange)).sorted().create();
tracer.set(D);
tracer.chart(chart);
Tracer.delay();
// }

function BinarySearch(array, element) { // array = sorted array, element = element to be found
  let minIndex = /* 기준 범위의 왼쪽 끝 값 */;
  let maxIndex = /* 기준 범위의 오른쪽 끝 값 */;
  let testElement;

  while ( /* 탐색 종료 조건 입력 */) {
    const middleIndex = Math.floor( /* 선택한 원소와 비교할 기준 원소 선택. 현재 범위의 중앙값 */);
    testElement = /* 현재 배열에서 중앙값 선택 */;

    // 시각화 {
    tracer.select(minIndex, maxIndex);
    Tracer.delay();
    tracer.patch(middleIndex);
    logger.println(`Searching at index: ${middleIndex}`);
    Tracer.delay();
    tracer.depatch(middleIndex);
    tracer.deselect(minIndex, maxIndex);
    // }

    if ( /* 기준 값보다 찾으려는 값이 더 큰 경우 */) { 
      // 시각화 {
      logger.println('Going right.');
      // }
      /* 범위를 조절 */
    } else if ( /* 기준 값보다 찾으려는 값이 더 작은 경우 */) { 
      // 시각화 {
      logger.println('Going left.');
      // }
      /* 범위를 조절 */
    } else { // 값을 찾은 경우
      // 시각화 {
      logger.println(`${element} is found at position ${middleIndex}!`);
      tracer.select(middleIndex);
      // }

      /* 반환값을 입력 */
    }
  }

  logger.println(`${element} is not found!`);
  return -1;
}

const element = D[new Randomize.Integer(0, D.length - 1).create()]; // 찾으려는 값. 생성된 배열값중 임의 값을 선택함.

logger.println(`Using iterative binary search to find ${element}`); // 결과 출력
BinarySearch( /* 이진 검색 함수를 실행할 배열과 찾을 원소를 입력 */);
