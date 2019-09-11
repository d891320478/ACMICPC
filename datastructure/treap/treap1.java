class TreapNode {
    int key, val;
    int wht, sz, cnt;
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
        LEAF.cnt = 0;
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
        this.sz = this.cnt = 1;
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

    public String toString() {
        StringBuilder sb = new StringBuilder();
        dfs(root, sb);
        return sb.toString();
    }

    private void dfs(TreapNode rt, StringBuilder sb) {
        if (rt == leaf) {
            return;
        }
        sb.append(rt.key).append("[" + rt.sz + "]").append(" (");
        dfs(rt.ch[0], sb);
        sb.append(")(");
        dfs(rt.ch[1], sb);
        sb.append(" )");
    }

    public void insert(int key, int val) {
        insert(root, key, val, null, 0);
    }

    public void remove(int key) {
        remove(root, key, null, 0);
    }

    public int getKey(int index) {
        TreapNode rt = root;
        while (rt != leaf) {
            if (rt.sz - rt.ch[1].sz < index) {
                index -= rt.sz - rt.ch[1].sz;
                rt = rt.ch[1];
            } else if (index > rt.ch[0].sz) {
                return rt.key;
            } else {
                rt = rt.ch[0];
            }
        }
        return 0;
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
            ++x.cnt;
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
            if (x.cnt > 1) {
                --x.cnt;
                update(x);
                return;
            }
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

    private void update(TreapNode t) {
        t.sz = t.cnt + t.ch[0].sz + t.ch[1].sz;
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
