const { Tracer, Array1DTracer, GraphTracer, LogTracer, Layout, VerticalLayout } = require('algorithm-visualizer');

const G = [ // G[i][j] indicates whether the path from the i-th node to the j-th node exists or not
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
];

const T = [ // mapping to G as a binary tree , [i][0] indicates left child, [i][1] indicates right child
    [-1, -1],
    [0, 2],
    [-1, -1],
    [1, 4],
    [-1, -1],
    [3, 8],
    [-1, 7],
    [-1, -1],
    [6, 10],
    [-1, -1],
    [9, -1],
];

// visualizer {
const treeTracer = new GraphTracer('Traversal Post-order');
const arrayTracer = new Array1DTracer('Print Post-order');
const logger = new LogTracer('Log');
Layout.setRoot(new VerticalLayout([treeTracer, arrayTracer, logger]));
treeTracer.set(G);
treeTracer.layoutTree(5);
arrayTracer.set(new Array(T.length).fill('-'));
Tracer.delay();
// }

let index = 0; // 탐색 순서를 나타내는 인덱스

function postOrder(root, parent) {
    if (/*(알맞은 값 입력)*/) { // 가장 아래 노드까지 도착한 경우
        // visualizer {
        logger.println('No more nodes. Backtracking.');
        Tracer.delay();
        // }
        return;
    }

    // visualizer {
    logger.println(`Reached ${root}`);
    treeTracer.visit(root, parent);
    Tracer.delay();

    logger.println(` Going left from ${root}`);
    Tracer.delay();
    // }
    postOrder(/*(알맞은 값 입력)*/); // 현재 노드에서 왼쪽 자식 노드로 이동

    // visualizer {
    logger.println(` Going right from ${root}`);
    Tracer.delay();
    // }
    postOrder(T[root][1], root); // 현재 노드에서 오른쪽 자식 노드로 이동

    // visualizer {
    logger.println(`Printing ${root}`);
    treeTracer.leave(root);
    arrayTracer.patch(index++, root);
    Tracer.delay();
    // }
}

postOrder(5); // node with key 5 is the root
// visualizer {
logger.println('Finished');
// }