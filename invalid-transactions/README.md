<h2>1169. Invalid Transactions</h2><h3>Medium</h3><hr><div><p>A transaction is <em>possibly invalid</em> if:</p>

<ul>
	<li>the amount exceeds $1000, or;</li>
	<li>if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.</li>
</ul>

<p>Each transaction string <code>transactions[i]</code>&nbsp;consists of&nbsp;comma separated values representing&nbsp;the name, time (in minutes), amount, and city of the transaction.</p>

<p>Given a list of <code>transactions</code>,&nbsp;return a list of transactions that are possibly invalid.&nbsp; You may return the answer in any order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
<strong>Output:</strong> ["alice,20,800,mtv","alice,50,100,beijing"]
<strong>Explanation:</strong> The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
<strong>Output:</strong> ["alice,50,1200,mtv"]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
<strong>Output:</strong> ["bob,50,1200,mtv"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>transactions.length &lt;= 1000</code></li>
	<li>Each <code>transactions[i]</code> takes the form <code>"{name},{time},{amount},{city}"</code></li>
	<li>Each <code>{name}</code> and <code>{city}</code>&nbsp;consist of&nbsp;lowercase English letters, and have lengths between <code>1</code> and <code>10</code>.</li>
	<li>Each <code>{time}</code> consist of&nbsp;digits, and represent an integer between <code>0</code> and <code>1000</code>.</li>
	<li>Each <code>{amount}</code>&nbsp;consist of&nbsp;digits, and represent an integer between <code>0</code> and <code>2000</code>.</li>
</ul>
</div>