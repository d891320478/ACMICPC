class TreapNode {
    int key, val;
    int wht, sz;
    TreapNode[] ch;
    private static TreapNode LEAF = null;
    private static final Random RAND = new Random(System.currentTimeMillis());

    public static TreapNode leaf() {
        if (LEAF != null) {
            return LEAF;
        }
        LEAF = new TreapNode();
        LEAF.ch = new TreapNode[2];
        LEAF.ch[0] = LEAF.ch[1] = LEAF;
        LEAF.sz = 0;
        LEAF.key = -1;
        LEAF.val = -1;
        LEAF.wht = -2147483648;
        return LEAF;
    }

    private TreapNode() {
    }

    public TreapNode(int key, int val) {
        ch = new TreapNode[2];
        ch[0] = ch[1] = leaf();
        this.key = key;
        this.val = val;
        this.sz = 1;
        this.wht = RAND.nextInt(2147483647);
    }

    @Override
    public String toString() {
        return "key= " + key + ", val = " + val;
    }
}

class Treap {

    private TreapNode root, leaf;

    public Treap() {
        leaf = TreapNode.leaf();
        root = leaf;
    }

    public void insert(int key, int val) {
        insert(root, key, val, null, 0);
    }

    public void remove(int key) {
        remove(root, key, null, 0);
    }

    public int find(int key) {
        return find(root, key);
    }

    public int findLowerOrEqual(int key) {
        TreapNode rlt = findLowerOrEqual(root, key);
        return rlt == leaf ? -1 : rlt.key;
    }

    public int findUpperOrEqual(int key) {
        TreapNode rlt = findUpperOrEqual(root, key);
        return rlt == leaf ? -1 : rlt.key;
    }

    public int maxKey() {
        TreapNode t = root;
        while (t.ch[1] != leaf) {
            t = t.ch[1];
        }
        return t.key;
    }

    public int size() {
        return root.sz;
    }

    private void insert(TreapNode x, int key, int val, TreapNode px, int pt) {
        if (x == leaf) {
            x = new TreapNode(key, val);
            if (px != null) {
                px.ch[pt] = x;
            } else {
                root = x;
            }
            return;
        }
        if (key == x.key) {
            x.val = val;
        } else {
            int son = key < x.key ? 0 : 1;
            insert(x.ch[son], key, val, x, son);
            if (x.wht < x.ch[son].wht) {
                rotate(x, son, px, pt);
            }
        }
        update(x);
    }

    private void remove(TreapNode x, int key, TreapNode px, int pt) {
        if (x == leaf) {
            return;
        }
        if (x.key == key) {
            if (x.ch[0] == leaf && x.ch[1] == leaf) {
                if (px == null) {
                    root = leaf;
                } else {
                    px.ch[pt] = leaf;
                }
                return;
            }
            int son = x.ch[0].wht > x.ch[1].wht ? 0 : 1;
            rotate(x, son, px, pt);
            remove(x, key, px == null ? root : px.ch[pt], son ^ 1);
        } else {
            int son = key < x.key ? 0 : 1;
            remove(x.ch[son], key, x, son);
        }
        update(x);
    }

    private int find(TreapNode x, int key) {
        if (x == leaf) {
            return -1;
        }
        if (x.key == key) {
            return x.val;
        }
        return find(x.ch[key < x.key ? 0 : 1], key);
    }

    private TreapNode findLowerOrEqual(TreapNode x, int key) {
        if (x == leaf) {
            return leaf;
        }
        if (x.key == key) {
            return x;
        }
        if (x.key > key) {
            return findLowerOrEqual(x.ch[0], key);
        }
        TreapNode lv = findLowerOrEqual(x.ch[1], key);
        if (lv == leaf || lv.key > key) {
            return x;
        } else {
            return lv;
        }
    }

    private TreapNode findUpperOrEqual(TreapNode x, int key) {
        if (x == leaf) {
            return leaf;
        }
        if (x.key == key) {
            return x;
        }
        if (x.key < key) {
            return findUpperOrEqual(x.ch[1], key);
        }
        TreapNode lv = findUpperOrEqual(x.ch[0], key);
        if (lv == leaf || lv.key < key) {
            return x;
        } else {
            return lv;
        }
    }

    private void update(TreapNode t) {
        t.sz = 1 + t.ch[0].sz + t.ch[1].sz;
    }

    private void rotate(TreapNode x, int t, TreapNode px, int pt) {
        TreapNode s = x.ch[t];
        x.ch[t] = s.ch[t ^ 1];
        s.ch[t ^ 1] = x;
        update(x);
        update(s);
        if (px != null) {
            px.ch[pt] = s;
        } else {
            root = s;
        }
    }
}
