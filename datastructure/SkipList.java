public class SkipList {

    private static final double P = 0.25;
    private static final int MAX_LEVEL = 16;

    private static class Node {
        final Node[] next;
        final int key;
        int count;

        Node(int level, int key) {
            this.next = new Node[level];
            this.key = key;
            this.count = 1;
        }
    }

    private final Node head = new Node(MAX_LEVEL, 0);
    // 当前使用中的层数，至少为 1
    private int curLevel = 1;

    public boolean search(int target) {
        Node s = head;
        for (int i = curLevel - 1; i >= 0; --i) {
            while (s.next[i] != null && s.next[i].key < target) {
                s = s.next[i];
            }
            if (s.next[i] != null && s.next[i].key == target) {
                return true;
            }
        }
        return false;
    }

    public void add(int num) {
        Node[] update = new Node[MAX_LEVEL];
        Node t = lowerBound(num, update);
        if (t != null && t.key == num) {
            ++t.count;
            return;
        }
        int level = randomLevel();
        for (int i = curLevel; i < level; ++i) {
            update[i] = head;
        }
        curLevel = Math.max(curLevel, level);
        Node node = new Node(level, num);
        for (int i = 0; i < level; ++i) {
            node.next[i] = update[i].next[i];
            update[i].next[i] = node;
        }
    }

    public boolean erase(int num) {
        Node[] update = new Node[MAX_LEVEL];
        Node t = lowerBound(num, update);
        if (t == null || t.key != num) {
            return false;
        }
        if (t.count > 1) {
            --t.count;
            return true;
        }
        for (int i = 0; i < t.next.length; ++i) {
            update[i].next[i] = t.next[i];
        }
        while (curLevel > 1 && head.next[curLevel - 1] == null) {
            --curLevel;
        }
        return true;
    }

    // 返回第一个 key >= target 的节点，并在 update 中记录每层的前驱
    private Node lowerBound(int target, Node[] update) {
        Node s = head;
        for (int i = curLevel - 1; i >= 0; --i) {
            while (s.next[i] != null && s.next[i].key < target) {
                s = s.next[i];
            }
            update[i] = s;
        }
        return s.next[0];
    }

    // 返回新节点的层数，范围是 [1, MAX_LEVEL]
    private int randomLevel() {
        int level = 1;
        while (level < MAX_LEVEL && Math.random() < P) {
            ++level;
        }
        return level;
    }
}
