---


---

<h1 id="complex-opencl">Complex OpenCL</h1>
<p>This is a small library-like extension, mimicking the functionality of <code>&lt;complex.h&gt;</code>, which enables operations with complex numbers inside of the OpenCL kernels.</p>
<h2 id="definitions">Definitions</h2>
<p>This library will use <code>double</code> precision if your system supports it, otherwise, single-precision <code>float</code> type will be used.</p>
<ul>
<li>A complex number is declared as <code>cl_complex</code> and has a type <code>float2</code> or <code>double2</code>, depending on your system’s support
<ul>
<li>A <code>cl_complex num;</code> is composed of <code>num.x</code> and <code>num.y</code>, where <code>x</code> represents a <em>real</em> part and <code>y</code> -  <em>imaginary</em></li>
</ul>
</li>
<li>Constant <strong>i</strong> is defined as <code>I_cl</code>, and represents <code>(0.0, 1.0)</code></li>
<li>Constant <strong>pi</strong> is defined as <code>Pi_cl</code> and represents <code>3.14159265358979323846</code></li>
<li>Constant <strong>e</strong> is defined as <code>E_cl</code> and represents <code>2.718281828459045235360</code></li>
</ul>
<h2 id="function-descriptions">Function descriptions</h2>

<table>
<thead>
<tr>
<th>Declaration</th>
<th>Description</th>
<th>Return type</th>
</tr>
</thead>
<tbody>
<tr>
<td><code>float cl_creal(cl_complex n);</code></td>
<td>Returns <em>real</em> part of a number given as an argument</td>
<td>float/double</td>
</tr>
<tr>
<td><code>float cl_cimag(cl_complex n);</code></td>
<td>Returns <em>imaginary</em> part of a number given as an argument</td>
<td>float/double</td>
</tr>
<tr>
<td><code>float cl_cmod(cl_complex n);</code></td>
<td>Returns <em>modulus</em> (absolute value) of a number given as an argument</td>
<td>float/double</td>
</tr>
<tr>
<td><code>cl_complex cl_cadd(cl_complex a, cl_complex b);</code></td>
<td>Performs the <em>addition</em> of 2 complex numbers given as an argument, and returns a complex sum</td>
<td>cl_complex</td>
</tr>
<tr>
<td><code>cl_complex cl_cmult(cl_complex a, cl_complex b);</code></td>
<td>Performs the <em>multiplication</em> of 2 complex numbers given as an argument, and returns a complex product</td>
<td>cl_complex</td>
</tr>
<tr>
<td><code>cl_complex cl_cpow(cl_complex base , int exp);</code></td>
<td>Computes the <em>integer power</em> of a complex number given as an agrument and returns the result</td>
<td>cl_complex</td>
</tr>
<tr>
<td><code>cl_complex cl_cdiv(cl_complex a, cl_complex b);</code></td>
<td>Performs the <em>devision</em> of a complex numbers <code>a</code> by <code>b</code> given as an argument, and returns a complex result</td>
<td>cl_complex</td>
</tr>
<tr>
<td><code>float cl_carg(cl_complex a);</code></td>
<td>Finds an <em>argument</em> (it’s angle) of a complex number given as an argument, and returns a result</td>
<td>float/double</td>
</tr>
<tr>
<td><code>cl_complex cl_csqrt(cl_complex n);</code></td>
<td>Returns the <em>principal square root</em> of a complex number given as an argument and returns a result</td>
<td>cl_complex</td>
</tr>
<tr>
<td><code>cl_complex cl_cexp(cl_complex n);</code></td>
<td>Computes the <em>exponential function</em> of a complex number given as an argument and returns a result</td>
<td>cl_complex</td>
</tr>
<tr>
<td><code>cl_complex cl_clog(cl_complex z);</code></td>
<td>Computes the <em>logatirm</em> of the complex number given as an argument and returns a result</td>
<td>cl_complex</td>
</tr>
<tr>
<td><code>float cl_cdot(cl_complex a, cl_complex b);</code></td>
<td>Computes the <em>dot product</em> of 2 complex numbers given as an argument and returns a result</td>
<td>cl_complex</td>
</tr>
</tbody>
</table><h2 id="usage-considerations">Usage considerations</h2>
<ul>
<li>
<p><strong>All variables of type <code>cl_complex</code> should be initialized to 0</strong></p>
<pre><code> cl_complex			num = 0;
</code></pre>
</li>
<li>
<p><em>Real</em> and <em>Imaginary</em> parts should be declared excplicitly:</p>
<pre><code> cl_complex			num = 0;
 num.x = 1;
 num.y = 4;
</code></pre>
<p>Represents number <strong>1+4i</strong></p>
</li>
<li>
<p>If you need to perform an operation between a <em>complex</em> number and a <em>real</em> or <em>imaginary</em> number, you have to define this number as <em>complex</em> regardless, otherwise the behavior is undefined.</p>
<p>For example, to add <em>real</em> <strong>5</strong> to <em>complex</em> <strong>1+4i</strong>, you can do something like this :</p>
<pre><code> cl_complex		num = 0;
 cl_complex		real = 0;
 cl_complex		res = 0;

 num.x = 1;
 num.y = 4;

 real.x = 5;

 res = cl_cadd(num, real);

 printf("5 + 1+4i = %.1f+%.1fi\n", cl_creal(res), cl_cimag(res));
</code></pre>
<p><strong>Output:</strong></p>
<p><code>5 + 1+4i = 6+4i</code></p>
</li>
</ul>
<h2 id="how-to-use">How to use</h2>
<ul>
<li>
<p>Place <strong>cl_complex.h.cl</strong> file in your project <strong>includes</strong> directory</p>
</li>
<li>
<p>Use the <code>-I</code> flag with the path to the <strong>includes</strong> directory when building the OpenCL program</p>
<pre><code>  clBuildProgram(program, 1, &amp;device_id, "-I ./includes", NULL, NULL);
</code></pre>
</li>
<li>
<p>Include the file inside your OpenCL kernel as you would any other library</p>
<pre><code>  #include "cl_complex.h.cl"
</code></pre>
</li>
</ul>
<h2 id="section"></h2>
<p>If you have any questions or would like to expand this library, please let me know!</p>

