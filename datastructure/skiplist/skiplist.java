class Skiplist {

    class LrNode {
        public List<LrNode> pred, next;
        public int key, val, sz;

        public LrNode(int level, int key, int val) {
            this.pred = new ArrayList<>();
            this.next = new ArrayList<>();
            for (int i = 0; i <= level; ++i) {
                this.pred.add(null);
                this.next.add(null);
            }
            this.key = key;
            this.val = val;
            this.sz = 1;
        }
    }

    private double p = 0.25;
    private int maxLevel = 16;
    private LrNode rt;

    public Skiplist() {
        rt = new LrNode(maxLevel, 0, 0);
    }

    public boolean search(int target) {
        return searchNode(target) != null;
    }

    public void add(int num) {
        LrNode node = searchNode(num);
        if (node != null) {
            ++node.sz;
            return;
        }
        LrNode s = rt;
        int lv = getLevel();
        node = new LrNode(lv, num, 0);
        for (int i = maxLevel - 1; i >= 0;) {
            if (s.next.get(i) == null) {
                add(s, node, i, lv);
                --i;
            } else {
                LrNode t = s.next.get(i);
                if (t.key < num) {
                    s = t;
                } else {
                    add(s, node, i, lv);
                    --i;
                }
            }
        }
    }

    private void add(LrNode s, LrNode node, int i, int lv) {
        if (i <= lv) {
            node.pred.set(i, s);
            node.next.set(i, s.next.get(i));
            s.next.set(i, node);
            if (node.next.get(i) != null) {
                node.next.get(i).pred.set(i, node);
            }
        }
    }

    public boolean erase(int num) {
        LrNode node = searchNode(num);
        if (node == null) {
            return false;
        }
        if (node.sz > 1) {
            --node.sz;
            return true;
        }
        for (int i = node.pred.size() - 1; i >= 0; --i) {
            node.pred.get(i).next.set(i, node.next.get(i));
            if (node.next.get(i) != null) {
                node.next.get(i).pred.set(i, node.pred.get(i));
            }
        }
        return true;
    }

    private int getLevel() {
        int lv = 0;
        while (lv + 1 < maxLevel && Math.random() < p) {
            ++lv;
        }
        return lv;
    }

    private LrNode searchNode(int target) {
        LrNode s = rt;
        for (int i = maxLevel - 1; i >= 0;) {
            if (s.next.get(i) == null) {
                --i;
                continue;
            }
            LrNode t = s.next.get(i);
            if (t.key == target) {
                return t;
            }
            if (t.key < target) {
                s = t;
            } else {
                --i;
            }
        }
        return null;
    }
}