<h2>1087. Brace Expansion</h2><h3>Medium</h3><hr><div><p>A string <code>S</code>&nbsp;represents a list of words.</p>

<p>Each letter in the word has 1 or more options.&nbsp; If there is one option, the letter is represented as is.&nbsp; If there is more than one option, then curly braces delimit the options.&nbsp; For example, <code>"{a,b,c}"</code> represents options <code>["a", "b", "c"]</code>.</p>

<p>For example, <code>"{a,b,c}d{e,f}"</code> represents the list <code>["ade", "adf", "bde", "bdf", "cde", "cdf"]</code>.</p>

<p>Return all words that can be formed in this manner, in lexicographical order.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"{a,b}c{d,e}f"</span>
<strong>Output: </strong><span id="example-output-1">["acdf","acef","bcdf","bcef"]</span>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"abcd"</span>
<strong>Output: </strong><span id="example-output-2">["abcd"]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= S.length &lt;= 50</code></li>
	<li>There are no&nbsp;nested curly brackets.</li>
	<li>All characters inside a pair of&nbsp;consecutive opening and ending curly brackets are different.</li>
</ol>
</div>