class NumMatrix {
private:
    int n, m;
    vector<vector<int>> mat;
    vector<vector<long long>> seg;

    void build_y(int node_x, int lx, int rx, int node_y, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx)
                seg[node_x][node_y] = mat[lx][ly];
            else
                seg[node_x][node_y] = seg[2 * node_x][node_y] + seg[2 * node_x + 1][node_y];
        } else {
            int my = (ly + ry) / 2;
            build_y(node_x, lx, rx, 2 * node_y, ly, my);
            build_y(node_x, lx, rx, 2 * node_y + 1, my + 1, ry);
            seg[node_x][node_y] = seg[node_x][2 * node_y] + seg[node_x][2 * node_y + 1];
        }
    }

    void build_x(int node_x, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(2 * node_x, lx, mx);
            build_x(2 * node_x + 1, mx + 1, rx);
        }
        build_y(node_x, lx, rx, 1, 0, m - 1);
    }

    long long query_y(int node_x, int node_y, int ly, int ry, int qly, int qry) {
        if (qry < ly || qly > ry) return 0;
        if (qly <= ly && ry <= qry) return seg[node_x][node_y];
        int my = (ly + ry) / 2;
        return query_y(node_x, 2 * node_y, ly, my, qly, qry) +
               query_y(node_x, 2 * node_y + 1, my + 1, ry, qly, qry);
    }

    long long query_x(int node_x, int lx, int rx, int qlx, int qrx, int qly, int qry) {
        if (qrx < lx || qlx > rx) return 0;
        if (qlx <= lx && rx <= qrx)
            return query_y(node_x, 1, 0, m - 1, qly, qry);
        int mx = (lx + rx) / 2;
        return query_x(2 * node_x, lx, mx, qlx, qrx, qly, qry) +
               query_x(2 * node_x + 1, mx + 1, rx, qlx, qrx, qly, qry);
    }

    void update_y(int node_x, int lx, int rx, int node_y, int ly, int ry, int x, int y, int new_val) {
        if (ly == ry) {
            if (lx == rx)
                seg[node_x][node_y] = new_val;
            else
                seg[node_x][node_y] = seg[2 * node_x][node_y] + seg[2 * node_x + 1][node_y];
        } else {
            int my = (ly + ry) / 2;
            if (y <= my)
                update_y(node_x, lx, rx, 2 * node_y, ly, my, x, y, new_val);
            else
                update_y(node_x, lx, rx, 2 * node_y + 1, my + 1, ry, x, y, new_val);
            seg[node_x][node_y] = seg[node_x][2 * node_y] + seg[node_x][2 * node_y + 1];
        }
    }

    void update_x(int node_x, int lx, int rx, int x, int y, int new_val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx)
                update_x(2 * node_x, lx, mx, x, y, new_val);
            else
                update_x(2 * node_x + 1, mx + 1, rx, x, y, new_val);
        }
        update_y(node_x, lx, rx, 1, 0, m - 1, x, y, new_val);
    }

public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        n = matrix.size();
        m = matrix[0].size();
        seg.resize(4 * n, vector<long long>(4 * m, 0));
        build_x(1, 0, n - 1);
    }

    void update(int row, int col, int val) {
        update_x(1, 0, n - 1, row, col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return query_x(1, 0, n - 1, row1, row2, col1, col2);
    }
};
