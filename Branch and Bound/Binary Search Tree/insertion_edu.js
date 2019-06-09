const { Tracer, Array1DTracer, GraphTracer, LogTracer, Layout, VerticalLayout } = require('algorithm-visualizer');

const T = {};

const elements = [5, 8, 10, 3, 1, 6, 9, 7, 2, 0, 4]; // item to be inserted
// visuzlier {
const graphTracer = new GraphTracer(' BST - Elements marked red indicates the current status of tree ');
const elemTracer = new Array1DTracer(' Elements ');
const logger = new LogTracer(' Log ');
Layout.setRoot(new VerticalLayout([graphTracer, elemTracer, logger]));
elemTracer.set(elements);
graphTracer.log(logger);
Tracer.delay();
// }

function bstInsert(root, element, parent) { // root = current node , parent = previous node
    // visualizer {
    graphTracer.visit(root, parent);
    Tracer.delay();
    // }
    const treeNode = /*(알맞은 값 입력)*/; // root 노드
    let propName = '';
    if (/*(알맞은 값 입력)*/) { // 삽입하려는 값이 root 값보다 작은 경우
        propName = 'left';
    } else if (/*(알맞은 값 입력)*/) { // 삽입하려는 값이 root 값보다 큰 경우
        propName = 'right';
    }
    if (propName !== '') {
        if (!(propName in treeNode)) { // insert as left child of root
            treeNode[propName] = /*(알맞은 값 입력)*/; // 왼쪽 노드에 값 삽입
            T[element] = {};
            // visualizer {
            graphTracer.addNode(element);
            graphTracer.addEdge(root, element);
            graphTracer.select(element, root);
            Tracer.delay();
            graphTracer.deselect(element, root);
            logger.println(`${element} Inserted`);
            // }
        } else { // 현재 삽입하려는 값이 부모 노드 보다 값이 큰 경우
            bstInsert(/*(알맞은 값 입력)*/, /*(알맞은 값 입력)*/, /*(알맞은 값 입력)*/);
        }
    }
    // visualizer {
    graphTracer.leave(root, parent);
    Tracer.delay();
    // }
}

const Root = elements[0]; // take first element as root
T[Root] = {};
// visualizer {
graphTracer.addNode(Root);
graphTracer.layoutTree(Root, true);
logger.println(`${Root} Inserted as root of tree `);
// }

for (let i = 1; i < elements.length; i++) {
    // visualizer {
    elemTracer.select(i);
    Tracer.delay();
    // }
    bstInsert(Root, elements[i]); // insert ith element
    // visualizer {
    elemTracer.deselect(i);
    Tracer.delay();
    // }
}
