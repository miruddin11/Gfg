//{ Driver Code Starts
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tc = scanner.nextInt();
        while (tc-- > 0) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            char[][] grid = new char[n][m];

            // Read the grid input
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = scanner.next().charAt(0);
                }
            }
            Solution obj = new Solution();
            int ans = obj.countIslands(grid);
            System.out.println(ans);
            System.out.println("~");
        }
        scanner.close();
    }
}

// } Driver Code Ends


class Solution {
 public int countIslands(char[][] grid) {
        // Code here
        int n=grid.length;
        int m=grid[0].length;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L'){
                    dfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
        
    }
    public static void dfs(char[][] grid,int i,int j,int n,int m){
        grid[i][j]='K';
        for(int r=-1;r<=1;r++){
            for(int c=-1;c<=1;c++){
                int nr=i+r;
                int nc=j+c;
                if(nr>=0 && nr<n && nc<m && nc>=0 && grid[nr][nc]=='L'){
                   dfs(grid,nr,nc,n,m);
                }
            }
        }
        
    }
}

