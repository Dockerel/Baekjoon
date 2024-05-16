import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static StringTokenizer st;
    private static List<Point> pointList = new ArrayList<>();
    private static int t;
    private static int n;
    private static Point root;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            pointList.clear();
            n = Integer.parseInt(br.readLine());
            int row = n / 5;
            int min_col = n % 5;
            for (int i = 0; i < row; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 5; j++) {
                    pointList.add(new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
                }
            }
            if (min_col > 0) {
                st = new StringTokenizer(br.readLine());
                for (int i = 0; i < min_col; i++) {
                    pointList.add(new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
                }
            }

            List<Point> ret = go();
            bw.write(ret.size() + "\n");
            for (Point pt : ret) {
                bw.write(Integer.toString(pt.x) + " " + Integer.toString(pt.y) + "\n");
            }
            bw.flush();
        }
        bw.close();
    }

    private static ArrayList<Point> go() {
        root = pointList.get(0);
        for (int i = 1; i < n; i++) {
            Point temp = pointList.get(i);
            if (root.y < temp.y)
                root = temp;
            else if (root.y == temp.y) {
                if (root.x > temp.x)
                    root = temp;
            }
        }

        Collections.sort(pointList);

        Stack<Point> stack = new Stack<>();
        stack.add(root);

        for (int i = 1; i < pointList.size(); i++) {
            while (stack.size() > 1
                    && ccw(stack.get(stack.size() - 2), stack.get(stack.size() - 1), pointList.get(i)) >= 0) {
                stack.pop();
            }
            stack.add(pointList.get(i));
        }

        return new ArrayList<>(stack);
    }

    private static int ccw(Point a, Point b, Point c) {
        Point v1 = new Point(b.x - a.x, b.y - a.y);
        Point v2 = new Point(c.x - a.x, c.y - a.y);
        int op = v1.x * v2.y - v2.x * v1.y;
        return op > 0 ? 1 : (op == 0 ? 0 : -1);
    }

    private static class Point implements Comparable<Point> {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point point) { // point -> this 순서
            int res = ccw(root, this, point);
            if (res > 0)
                return 1;
            else if (res < 0)
                return -1;
            else {
                if (dist(root, this) < dist(root, point))
                    return -1;
                else
                    return 1;
            }
        }
    }

    private static double dist(Point p1, Point p2) {
        return Math.sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
}
