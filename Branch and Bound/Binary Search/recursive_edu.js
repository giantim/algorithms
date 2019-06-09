const { Tracer, Array1DTracer, ChartTracer, LogTracer, Randomize, Layout, VerticalLayout } = require('algorithm-visualizer');

// visualizer {
const chart = new ChartTracer();
const tracer = new Array1DTracer();
const logger = new LogTracer();
Layout.setRoot(new VerticalLayout([chart, tracer, logger]));
const D = new Randomize.Array1D(15, new Randomize.Integer(0, 50)).sorted().create();
tracer.set(D);
tracer.chart(chart);
Tracer.delay();
// }

function BinarySearch(array, element, minIndex, maxIndex) { // array = sorted array, element = element to be found, minIndex = low index, maxIndex = high index
  if (minIndex > maxIndex) {
    // visualizer {
    logger.println(`${element} is not found!`);
    // }
    return -1;
  }

  const middleIndex = Math.floor(/*(알맞은 값 입력)*/);
  const testElement = /*(알맞은 값 입력)*/;

  // visuzlier {
  tracer.select(minIndex, maxIndex);
  Tracer.delay();
  tracer.patch(middleIndex);
  logger.println(`Searching at index: ${middleIndex}`);
  Tracer.delay();
  tracer.depatch(middleIndex);
  tracer.deselect(minIndex, maxIndex);
  // }

  if (/*(알맞은 값 입력)*/) { // 찾는 원소가 기준 값보다 클 때
    // visualizer {
    logger.println('Going right.');
    // }
    return BinarySearch(array, element, /*(알맞은 값 입력)*/, /*(알맞은 값 입력)*/);
  }

  if (/*(알맞은 값 입력)*/) { // 찾는 원소가 기준 값보다 작을 때
    // visualizer {
    logger.println('Going left.');
    // }
    return BinarySearch(array, element, /*(알맞은 값 입력)*/, /*(알맞은 값 입력)*/);
  }

  if (/*(알맞은 값 입력)*/) { // 원소를 찾았을 때
    // visualizer {
    logger.println(`${element} is found at position ${middleIndex}!`);
    tracer.select(middleIndex);
    // }
    return /*(알맞은 값 입력)*/;
  }

  // visualizer {
  logger.println(`${element} is not found!`);
  // }
  return -1;
}

const element = D[new Randomize.Integer(0, D.length - 1).create()];

// visualizer {
logger.println(`Using binary search to find ${element}`);
// }
BinarySearch(D, element, 0, D.length - 1);
