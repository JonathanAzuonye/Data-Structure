<?php

class Node {
    public $value;
    public $next;
    public $index;

    public function __construct($value, $next, $index) {
        $this->value = $value;
        $this->next = $next;
        $this->index = $index;
    }

    public function delete() {
        $this->next = $this->next->next;
    }
}

class SinglyLinked {
    public $list;
    public $length;

    public function __construct() {
        $this->list = null;
        $this->length = 0;
    }

    public function insert($value) {
        $node = new Node($value, $this->list, $this->length);
        $this->list = $node;
        $this->length++;
    }

    public function checkIfExists($val) {
        $data = $this->list;
        $ans = 'Not Found';
        while ($data != null) {
            if ($data->value == $val) {
                $ans = 'Found';
                break;
            } else {
                $data = $data->next;
            }
        }
        return $ans;
    }

    public function getNode($index) {
        $data = $this->list;
        $ans = 'Index Not Found';
        while ($data != null) {
            if ($data->index == $index) {
                $ans = $data;
                break;
            } else {
                $data = $data->next;
            }
        }
        return $ans;
    }

    public function remove($index) {
        $this->getNode($index + 1)->delete();
        $data = $this->list;
        $this->length--;
        while ($data != null) {
            if ($data->index < $index) {
                break;
            }
            $data->index--;
            $data = $data->next;
        }
    }
}

?>
