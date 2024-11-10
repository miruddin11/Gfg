<h2><a href="https://www.geeksforgeeks.org/problems/k-sum-paths/1">K Sum Paths</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;"><span style="box-sizing: border-box; margin: 0px; padding: 0px; border: 0px; vertical-align: baseline; color: #273239; font-family: Nunito, sans-serif; letter-spacing: 0.162px; background-color: #ffffff;">Given a binary tree and an integer&nbsp;</span><strong style="box-sizing: border-box; margin: 0px; padding: 0px; border: 0px; vertical-align: baseline; color: #273239; font-family: Nunito, sans-serif; letter-spacing: 0.162px; background-color: #ffffff;"><strong style="box-sizing: border-box; margin: 0px; padding: 0px; border: 0px; vertical-align: baseline;">k</strong></strong><span style="box-sizing: border-box; margin: 0px; padding: 0px; border: 0px; vertical-align: baseline; color: #273239; font-family: Nunito, sans-serif; letter-spacing: 0.162px; background-color: #ffffff;">, the task is to count the number of paths in the tree such that the sum of the nodes in each path equals&nbsp;</span><strong style="box-sizing: border-box; margin: 0px; padding: 0px; border: 0px; vertical-align: baseline; color: #273239; font-family: Nunito, sans-serif; letter-spacing: 0.162px; background-color: #ffffff;"><strong style="box-sizing: border-box; margin: 0px; padding: 0px; border: 0px; vertical-align: baseline;">k</strong></strong><span style="box-sizing: border-box; margin: 0px; padding: 0px; border: 0px; vertical-align: baseline; color: #273239; font-family: Nunito, sans-serif; letter-spacing: 0.162px; background-color: #ffffff;">. A path can start from any node and end at any node and must be <strong>downward </strong>only.</span><br></span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>Tree =  1  k = 3                               
             /   \                          
           2     3</span>
<span style="font-size: 18px;"><strong>Output:</strong> 2</span>
<span style="font-size: 18px;"><strong>Explanation:</strong>
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>Tree = 8  k = 7  
            /   \
          4      5
         /   \       \
       3     2       2                        
      /   \     \                    
    3    -2    1       <br><strong>Output:</strong> 3</span>
<span style="font-size: 18px;"><strong>Explanation: </strong>The following paths sum to k <br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700575/Web/Other/blobid0_1722330388.jpg" width="313" height="313"> </span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n)<br><strong>Expected Auxiliary Space:</strong> O(height of Tree)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ number of nodes ≤ 2*10<sup>4</sup><br>-10<sup>5</sup> ≤ node value ≤ 10<sup>5</sup><br>-10<sup>9</sup> ≤ k ≤ 10<sup>9</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Walmart</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;