class Node {
    constructor(value, next, index) {
        this.value = value;
        this.next = next;
        this.index = index;
    }

    deleteNode() {
        this.next = this.next.next;
    }
}

class SinglyLinked {
    constructor() {
        this.list = null;
        this.length = 0;
    }

    insert(value) {
        const node = new Node(value, this.list, this.length);
        this.list = node;
        this.length++;
    }

    checkIfExists(val) {
        let data = this.list;
        let ans = 'Not Found';
        while (data) {
            if (data.value === val) {
                ans = 'Found';
                break;
            } else {
                data = data.next;
            }
        }
        return ans;
    }

    getNode(index) {
        let data = this.list;
        let ans = 'Index Not Found';
        while (data) {
            if (data.index === index) {
                ans = data;
                break;
            } else {
                data = data.next;
            }
        }
        return ans;
    }

    remove(index) {
        this.getNode(index + 1).deleteNode();
        let data = this.list;
        this.length--;
        while (data) {
            if (data.index < index) {
                break;
            }
            data.index--;
            data = data.next;
        }
    }

    print() {
        let data = this.list;
        let res = '';
        while (data) {
            res += `{ \n`;
            res += `Index: ${data.index},\n`;
            res += `Value: ${data.value},\n`;
            if (data.next !== null) {
                res += `Next: ${data.next.value}\n`;
            } else {
                res += `Next: Null\n`;
            }
            res += `} \n\n`;
            data = data.next;
        }
        console.log(res);
    }
}

const test = new SinglyLinked();
test.insert(3);
test.insert(15);
test.insert(25);
test.insert(33);
test.insert(43);
test.insert(83);
test.insert(45);
test.insert(38);
test.insert(37);
test.insert(12);

test.remove(3);
console.log(test.checkIfExists(33));