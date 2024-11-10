<h2><a href="https://www.geeksforgeeks.org/problems/connect-nodes-at-same-level/1">Connect Nodes at Same Level</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p>Given a binary tree, connect the nodes that are at the same level. You'll be given an addition <strong>nextRight&nbsp;</strong>pointer for the same.</p>
<p><strong>Initially</strong>, all the next night<strong>&nbsp;</strong>pointers point to <strong>garbage </strong>values. <strong>Your function</strong> should set these pointers to the point next right for each node.<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 10&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; 10 ------&gt; NULL<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; / \&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; /&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \<br>&nbsp;&nbsp;&nbsp;&nbsp; 3&nbsp;&nbsp; 5&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; =&gt; &nbsp;&nbsp;&nbsp; 3 ------&gt; 5 --------&gt; NULL<br>&nbsp;&nbsp;&nbsp; / \&nbsp; &nbsp;&nbsp; \&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp;&nbsp; /&nbsp; \&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \<br>&nbsp;&nbsp; 4&nbsp;&nbsp; 1&nbsp;&nbsp; 2&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; 4 --&gt; 1 -----&gt; 2 -------&gt; NULL</p>
<p>&nbsp;</p>
<p><strong>Examples:</strong></p>
<pre><span style="font-size: 14pt;"><strong>Input:
</strong>     3
&nbsp;  /  \
&nbsp; 1    2
<strong>Output:
</strong>[3, 1, 2]
[1, 3, 2]<strong>
Explanation:</strong>The connected tree is
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3 ------&gt; NULL
&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp;\
&nbsp;&nbsp;  1-----&gt; 2 ------ NULL
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:
</strong>      10
&nbsp;   /   \
&nbsp;  20   30
&nbsp; /  \
 40  60
<strong>Output:
</strong>[10, 20, 30, 40, 60]
[40, 20, 60, 10, 30]<strong>
Explanation:</strong>The connected tree is
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 10 ----------&gt; NULL
&nbsp;&nbsp;&nbsp;  &nbsp; /&nbsp;&nbsp;&nbsp;&nbsp; \
&nbsp;&nbsp;&nbsp;&nbsp; 20 ------&gt; 30 -------&gt; NULL
&nbsp;&nbsp;/&nbsp;&nbsp;&nbsp; \
&nbsp;40 ----&gt; 60 ----------&gt; NULL</span></pre>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input:
</strong><span style="font-size: 14pt;"> </span><span style="font-size: 18.6667px;">      15
     /  \
    10   20
   / \   / \
  8   12 18 25
</span>
<strong style="font-size: 14pt;">Output:
</strong><span style="font-size: 18.6667px;">[15, 10, 20, 8, 12, 18, 25]
[8, 10, 12, 15, 18, 20, 25]
</span><strong style="font-size: 14pt;">Explanation:</strong><span style="font-size: 14pt;">The connected tree is
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  </span></span><span style="font-size: 18.6667px;">15 ----------&gt; NULL
       /    \
     10 ------&gt; 20 --------&gt; NULL
    /  \        /  \
   8 --&gt; 12 --&gt;18 --&gt; 25 --&gt; NULL</span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong></span><br><span style="font-size: 14pt;">1 ≤ number of nodes ≤ 10<sup>5</sup></span><br><span style="font-size: 14pt;">0 ≤ node-&gt;data ≤ 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>OYO Rooms</code>&nbsp;<code>Ola Cabs</code>&nbsp;<code>Oracle</code>&nbsp;<code>Adobe</code>&nbsp;<code>Google</code>&nbsp;<code>Boomerang Commerce</code>&nbsp;<code>Xome</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;