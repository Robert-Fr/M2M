<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="fr" xml:lang="fr">
<head>
<title>Bare-Metal Development | M2M Lectures | Grenoble University | François ROBERT M2 - GI | January 12, 2021</title>
<!-- 2021-02-15 Mon 18:38 -->
<meta  http-equiv="Content-Type" content="text/html;charset=utf-8" />
<meta  name="generator" content="Org-mode" />
<meta  name="author" content="Francois Robert" />
<style type="text/css">
 <!--/*--><![CDATA[/*><!--*/
  .title  { text-align: center; }
  .todo   { font-family: monospace; color: red; }
  .done   { color: green; }
  .tag    { background-color: #eee; font-family: monospace;
            padding: 2px; font-size: 80%; font-weight: normal; }
  .timestamp { color: #bebebe; }
  .timestamp-kwd { color: #5f9ea0; }
  .right  { margin-left: auto; margin-right: 0px;  text-align: right; }
  .left   { margin-left: 0px;  margin-right: auto; text-align: left; }
  .center { margin-left: auto; margin-right: auto; text-align: center; }
  .underline { text-decoration: underline; }
  #postamble p, #preamble p { font-size: 90%; margin: .2em; }
  p.verse { margin-left: 3%; }
  pre {
    border: 1px solid #ccc;
    box-shadow: 3px 3px 3px #eee;
    padding: 8pt;
    font-family: monospace;
    overflow: auto;
    margin: 1.2em;
  }
  pre.src {
    position: relative;
    overflow: visible;
    padding-top: 1.2em;
  }
  pre.src:before {
    display: none;
    position: absolute;
    background-color: white;
    top: -10px;
    right: 10px;
    padding: 3px;
    border: 1px solid black;
  }
  pre.src:hover:before { display: inline;}
  pre.src-sh:before    { content: 'sh'; }
  pre.src-bash:before  { content: 'sh'; }
  pre.src-emacs-lisp:before { content: 'Emacs Lisp'; }
  pre.src-R:before     { content: 'R'; }
  pre.src-perl:before  { content: 'Perl'; }
  pre.src-java:before  { content: 'Java'; }
  pre.src-sql:before   { content: 'SQL'; }

  table { border-collapse:collapse; }
  caption.t-above { caption-side: top; }
  caption.t-bottom { caption-side: bottom; }
  td, th { vertical-align:top;  }
  th.right  { text-align: center;  }
  th.left   { text-align: center;   }
  th.center { text-align: center; }
  td.right  { text-align: right;  }
  td.left   { text-align: left;   }
  td.center { text-align: center; }
  dt { font-weight: bold; }
  .footpara:nth-child(2) { display: inline; }
  .footpara { display: block; }
  .footdef  { margin-bottom: 1em; }
  .figure { padding: 1em; }
  .figure p { text-align: center; }
  .inlinetask {
    padding: 10px;
    border: 2px solid gray;
    margin: 10px;
    background: #ffffcc;
  }
  #org-div-home-and-up
   { text-align: right; font-size: 70%; white-space: nowrap; }
  textarea { overflow-x: auto; }
  .linenr { font-size: smaller }
  .code-highlighted { background-color: #ffff00; }
  .org-info-js_info-navigation { border-style: none; }
  #org-info-js_console-label
    { font-size: 10px; font-weight: bold; white-space: nowrap; }
  .org-info-js_search-highlight
    { background-color: #ffff00; color: #000000; font-weight: bold; }
  /*]]>*/-->
</style>
<script type="text/javascript">
/*
@licstart  The following is the entire license notice for the
JavaScript code in this tag.
Copyright (C) 2012-2013 Free Software Foundation, Inc.
The JavaScript code in this tag is free software: you can
redistribute it and/or modify it under the terms of the GNU
General Public License (GNU GPL) as published by the Free Software
Foundation, either version 3 of the License, or (at your option)
any later version.  The code is distributed WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU GPL for more details.
As additional permission under GNU GPL version 3 section 7, you
may distribute non-source (e.g., minimized or compacted) forms of
that code without the copy of the GNU GPL normally required by
section 4, provided you include this license notice and a URL
through which recipients can access the Corresponding Source.
@licend  The above is the entire license notice
for the JavaScript code in this tag.
*/
<!--/*--><![CDATA[/*><!--*/
 function CodeHighlightOn(elem, id)
 {
   var target = document.getElementById(id);
   if(null != target) {
     elem.cacheClassElem = elem.className;
     elem.cacheClassTarget = target.className;
     target.className = "code-highlighted";
     elem.className   = "code-highlighted";
   }
 }
 function CodeHighlightOff(elem, id)
 {
   var target = document.getElementById(id);
   if(elem.cacheClassElem)
     elem.className = elem.cacheClassElem;
   if(elem.cacheClassTarget)
     target.className = elem.cacheClassTarget;
 }
/*]]>*///-->
</script>
<script type="text/javascript" src="http://orgmode.org/mathjax/MathJax.js"></script>
<script type="text/javascript">
<!--/*--><![CDATA[/*><!--*/
    MathJax.Hub.Config({
        // Only one of the two following lines, depending on user settings
        // First allows browser-native MathML display, second forces HTML/CSS
        //  config: ["MMLorHTML.js"], jax: ["input/TeX"],
            jax: ["input/TeX", "output/HTML-CSS"],
        extensions: ["tex2jax.js","TeX/AMSmath.js","TeX/AMSsymbols.js",
                     "TeX/noUndefined.js"],
        tex2jax: {
            inlineMath: [ ["\\(","\\)"] ],
            displayMath: [ ['$$','$$'], ["\\[","\\]"], ["\\begin{displaymath}","\\end{displaymath}"] ],
            skipTags: ["script","noscript","style","textarea","pre","code"],
            ignoreClass: "tex2jax_ignore",
            processEscapes: false,
            processEnvironments: true,
            preview: "TeX"
        },
        showProcessingMessages: true,
        displayAlign: "center",
        displayIndent: "2em",

        "HTML-CSS": {
             scale: 100,
             availableFonts: ["STIX","TeX"],
             preferredFont: "TeX",
             webFont: "TeX",
             imageFont: "TeX",
             showMathMenu: true,
        },
        MMLorHTML: {
             prefer: {
                 MSIE:    "MML",
                 Firefox: "MML",
                 Opera:   "HTML",
                 other:   "HTML"
             }
        }
    });
/*]]>*///-->
</script>
</head>
<body>
<div id="content">
<h1 class="title">Bare-Metal Development | M2M Lectures | Grenoble University | François ROBERT M2 - GI | January 12, 2021</h1>
<div id="table-of-contents">
<h2>Table des matières</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#sec-1">1. Preface by Pr. Olivier Gruber</a></li>
<li><a href="#sec-2">2. QEMU</a></li>
<li><a href="#sec-3">3. GNU Debugger</a></li>
<li><a href="#sec-4">4. Makefile</a>
<ul>
<li><a href="#sec-4-1">4.1. What is the TOOLCHAIN?</a></li>
<li><a href="#sec-4-2">4.2. What are VersatilePB and VersatileAB?</a></li>
<li><a href="#sec-4-3">4.3. What is a linker script? Look at the linker option ”-T”</a></li>
<li><a href="#sec-4-4">4.4. Read and understand the linker script that we use</a></li>
<li><a href="#sec-4-5">4.5. Why do we translate the ”kernel.elf” into a ”kernel.bin” via ”objcopy”</a></li>
<li><a href="#sec-4-6">4.6. What ensures that we can debug?</a></li>
<li><a href="#sec-4-7">4.7. What is the meaning of the ”-nostdlib” option? Why is it necessary?</a></li>
<li><a href="#sec-4-8">4.8. Try MEMORY=32K, it fails, why? Look at the linker script.</a></li>
<li><a href="#sec-4-9">4.9. Could you use printf in the code? Why?</a></li>
</ul>
</li>
<li><a href="#sec-5">5. Linker Script</a></li>
<li><a href="#sec-6">6. ELF Format</a></li>
<li><a href="#sec-7">7. Startup Code</a></li>
<li><a href="#sec-8">8. Main Code</a>
<ul>
<li><a href="#sec-8-1">8.1. What is an UART and a serial line?</a></li>
<li><a href="#sec-8-2">8.2. What is the purpose of a serial line here?</a></li>
<li><a href="#sec-8-3">8.3. What is the relationship between this serial line and the Terminal window</a></li>
<li><a href="#sec-8-4">8.4. What is the special testing of the value 13 as a special character and why do we send back ’\r’ and ’\n’ ?</a></li>
<li><a href="#sec-8-5">8.5. Why can we say this program polls the serial line? Although it works,why is it not a good idea?</a></li>
<li><a href="#sec-8-6">8.6. How could using hardware interrupts be a better solution?</a></li>
<li><a href="#sec-8-7">8.7. Could we say that the function uart send may block? Why?</a></li>
<li><a href="#sec-8-8">8.8. Could we say that the function uart receive is non-blocking? Why?</a></li>
<li><a href="#sec-8-9">8.9. Explain why uart send is blocking and uart receive is non-blocking.</a></li>
</ul>
</li>
<li><a href="#sec-9">9. Test Code</a>
<ul>
<li><a href="#sec-9-1">9.1. Blocking Uart-Receive</a></li>
<li><a href="#sec-9-2">9.2. Adding Printing</a></li>
<li><a href="#sec-9-3">9.3. Line editing</a></li>
</ul>
</li>
<li><a href="#sec-10">10. Laboratory Log</a>
<ul>
<li><a href="#sec-10-1">10.1. Interruptions handling :</a>
<ul>
<li><a href="#sec-10-1-1">10.1.1. Ce que j’ai compris du chapitre “Processor modes” et “Exceptions” de la doc de l’architecture ARMv5 :</a></li>
<li><a href="#sec-10-1-2">10.1.2. Ce que j'ai mis en place dans le code</a></li>
</ul>
</li>
<li><a href="#sec-10-2">10.2. Linux Distribution :</a>
<ul>
<li><a href="#sec-10-2-1">10.2.1. Minidist directory</a></li>
<li><a href="#sec-10-2-2">10.2.2. GRUB Bootloader</a></li>
<li><a href="#sec-10-2-3">10.2.3. Minimal File-System Layout</a></li>
<li><a href="#sec-10-2-4">10.2.4. The "init" process</a></li>
<li><a href="#sec-10-2-5">10.2.5. The shell Setup</a></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>




<div id="outline-container-sec-1" class="outline-2">
<h2 id="sec-1"><span class="section-number-2">1</span> Preface by Pr. Olivier Gruber</h2>
<div class="outline-text-2" id="text-1">
<p>
This document is your work log for the first step in the M2M course, master-
level, at the University of Grenoble, France. You will have such a document for
each step of our course together.
This document has two parts. One part is about diverse sections, each with
a bunch of questions that you have to answers. The other part is really a
laboratory log, keeping track of what you do, as you do it.
The questions provide a guideline for your learning. They are not about
getting a good grade if you answer them correctly, they are about giving your
pointers on what to learn about.
The goal of the questions is therefore not to be answered in three lines of
text and be forgotten about. The questions must be researched and thoroughly
understood. Ask questions around you if things are unclear, to your fellow
students and to me, your professor.
Writing down the answers to the questions is a tool for helping your learn
and remember. Also, it keeps track of what you know, the URLs you visited,
the open questions that you are trouble with, etc. The tools you used. It is
intended to be a living document, written as you go.
Ultimately, the goal of the document is to be kept for your personal records.
If ever you will work on embedded systems, trust me, you will be glad to have
a written trace about all this.
REMEMBER: plaggia is a crime that can get you evicted forever from
french universities&#x2026; The solution is simple, write using your own words or
quote, giving the source of the quoted text. Also, remember that you do not
learn through cut&amp;paste. You also do not learn much by watching somebody
else doing.
</p>
</div>
</div>

<div id="outline-container-sec-2" class="outline-2">
<h2 id="sec-2"><span class="section-number-2">2</span> QEMU</h2>
<div class="outline-text-2" id="text-2">
<ul class="org-ul">
<li><code>What is QEMU? Why is it necessary here?</code>
</li>
</ul>

<p>
→ QEMU est utilisé pour émuler du matériel : ici on veut émuler une “ARM-based board, the VersatilePB board” ( README - ligne 2 ), on peut parametrer la machine émuler : la quantité de RAM, le type de processeur etc …
C’est nécessaire ici car nous n’avons pas d’exemplaire de carte chez nous, on se contente donc de simuler son comportement de façon logicielle.
</p>

<p>
<code>Read the README-QEMU-ARM.</code>
</p>

<p>
<code>Try it... with ”make run”</code>
→ les installations sur mon environnement de travail on été faites : ça tourne
</p>
</div>
</div>

<div id="outline-container-sec-3" class="outline-2">
<h2 id="sec-3"><span class="section-number-2">3</span> GNU Debugger</h2>
<div class="outline-text-2" id="text-3">
<p>
<code>Here, try single-stepping the code via the GNU debugger (GDB).</code>
<code>Read the README-GDB.</code>
<code>Try it, in one shell, launch QEMU in debug mode and in another shell launch</code>
<code>gdb.</code>
 → dans un terminal : 
</p>
<ul class="org-ul">
<li>make debug
</li>
</ul>
<p>
ça lance le programme sur qemu avec l’option -S etc pour permettre à gdb de se connecter sur le port 1234.
Dans un autre terminal : 
</p>
<ul class="org-ul">
<li>gdb-multiarch kernel.elf
</li>
</ul>
<p>
quand le prompt gdb apparait : 
</p>
<ul class="org-ul">
<li>target remote:1234
</li>
</ul>
<p>
A partir de la on peut utiliser gdb de façon normale en ligne de commande.
</p>
</div>
</div>

<div id="outline-container-sec-4" class="outline-2">
<h2 id="sec-4"><span class="section-number-2">4</span> Makefile</h2>
<div class="outline-text-2" id="text-4">
<p>
You need to read and fully understand the provided makefile. Please find a
few questions below highlighting important points of that makefile. These ques-
tions are there only to guide your reading of the makefile. Make sure they
are addressed in your overall writing about the makefile and the corresponding
challenge of building bare-metal software.
</p>
</div>

<div id="outline-container-sec-4-1" class="outline-3">
<h3 id="sec-4-1"><span class="section-number-3">4.1</span> What is the TOOLCHAIN?</h3>
<div class="outline-text-3" id="text-4-1">
<p>
        La “Tool chain” définit l’ensemble des paquets utilisé pour la compilation d’un programme,
ici on veut cibler une architecture ARM donc on utilise “arm-none-eabi”.
</p>
</div>
</div>

<div id="outline-container-sec-4-2" class="outline-3">
<h3 id="sec-4-2"><span class="section-number-3">4.2</span> What are VersatilePB and VersatileAB?</h3>
<div class="outline-text-3" id="text-4-2">
<p>
On a vu que l’on pouvait définir la machine émulé par qemu, on voit que le makefile définit la variable “MACHINE” comme étant égal à “ VersatilePB” et “ VersatileAB” : Ce sont les machines que l’on va émuler avec la commande “make run”
</p>
</div>
</div>

<div id="outline-container-sec-4-3" class="outline-3">
<h3 id="sec-4-3"><span class="section-number-3">4.3</span> What is a linker script? Look at the linker option ”-T”</h3>
<div class="outline-text-3" id="text-4-3">
<p>
Le “linker script” est la suite de commande qui va faire le lien entre les différents .o obtenu par la compilation des fichiers .s, pour obtenir un .elf → l’executable que l’on obtient à la fin de la chaine de compilation.
L’option “-T” sert à lire le fichier .ld qui définit comment doivent être lié les différents .o (voir “man arm-none-eabi-ld”) pour contrôler la façon dont les fichiers objets seront liés. 
</p>
</div>
</div>

<div id="outline-container-sec-4-4" class="outline-3">
<h3 id="sec-4-4"><span class="section-number-3">4.4</span> Read and understand the linker script that we use</h3>
<div class="outline-text-3" id="text-4-4">
<p>
        Le fichier “kernel.ld” définit le format du fichier de sorti : kernel.elf 
(interprétation grâce au lien suivant : <a href="https://ftp.gnu.org/old-gnu/Manuals/ld-2.9.1/html_chapter/ld_3.html#SEC17">https://ftp.gnu.org/old-gnu/Manuals/ld-2.9.1/html_chapter/ld_3.html#SEC17</a> ) :
</p>
<ul class="org-ul">
<li>Définition du point d’entrée du programme :
</li>
</ul>
<p>
l’adresse de la première instruction qui sera executée au lancement du programme
</p>
<ul class="org-ul">
<li>Définiton des différentes sections : 
</li>
</ul>
<p>
.startup : zone text de startup.o
.text : zone text de tous les autres .o : le code de tous les autres fichiers
.data : zone data de tous les .o
.bss : pas compris
</p>
</div>
</div>

<div id="outline-container-sec-4-5" class="outline-3">
<h3 id="sec-4-5"><span class="section-number-3">4.5</span> Why do we translate the ”kernel.elf” into a ”kernel.bin” via ”objcopy”</h3>
<div class="outline-text-3" id="text-4-5">
<p>
C’est grâce à cela que le code peut être chargé en mémoire sur la board, la board ne peut pas comprendre les fichiers .elf.
</p>
</div>
</div>

<div id="outline-container-sec-4-6" class="outline-3">
<h3 id="sec-4-6"><span class="section-number-3">4.6</span> What ensures that we can debug?</h3>
<div class="outline-text-3" id="text-4-6">
<p>
C’est le fait que les .o sont obtenu par une compilation qui utilise l’option “-g” : le code compilé est un peu plus lourd car il contient des informations qui permettent le debogage par gdb.
</p>
</div>
</div>

<div id="outline-container-sec-4-7" class="outline-3">
<h3 id="sec-4-7"><span class="section-number-3">4.7</span> What is the meaning of the ”-nostdlib” option? Why is it necessary?</h3>
<div class="outline-text-3" id="text-4-7">
<p>
C’est pour ne pas inclure la librairie standard lors de la compilation des fichiers .c, nécessaire ici car cela voudrait dire que la librairie est définie quelque part sur la carte émulé, or ici ce n’est pas le cas (besoin de précisions).
</p>
</div>
</div>

<div id="outline-container-sec-4-8" class="outline-3">
<h3 id="sec-4-8"><span class="section-number-3">4.8</span> Try MEMORY=32K, it fails, why? Look at the linker script.</h3>
<div class="outline-text-3" id="text-4-8">
<p>
        → (3) Your guest kernel has a bug and crashed by jumping off into nowhere
Dans kernel.ld on définit le point d’entrée à 0x100000, si on que a 32kB de mémoire, un tel point d’entrée est en dehors de la zone mémoire aloué par qemu pour émuler la machine.
</p>
</div>
</div>

<div id="outline-container-sec-4-9" class="outline-3">
<h3 id="sec-4-9"><span class="section-number-3">4.9</span> Could you use printf in the code? Why?</h3>
<div class="outline-text-3" id="text-4-9">
<p>
Non on ne peut pas utiliser de printf dans le code, c’est une fonction de la librairie standard donc comme on ne l’inclue pas dans la compilation notre programme n’aurait pas connaissance du code de la fonction printf et ne pourrait donc pas l’utiliser.
</p>
</div>
</div>
</div>

<div id="outline-container-sec-5" class="outline-2">
<h2 id="sec-5"><span class="section-number-2">5</span> Linker Script</h2>
<div class="outline-text-2" id="text-5">
<p>
<code>Detail here your understanding of the linker script that we use.</code>
<code>Why do we translate the ”kernel.elf” into a ”kernel.bin” via ”objcopy”</code>
</p>

<p>
C’est grâce à cela que le code peut être chargé en mémoire sur la board, la board ne peut pas comprendre les fichiers .elf.
</p>

<p>
<code>Why do we link our code to run at the 0x10000?</code>
Car il semble que c’est à cette adresse que le processeur va commencer à lire le code quand il va “se réveiller”
</p>

<p>
<code>Why do we make sure the code for the object file ”startup.o” is first?</code>
Car c’est le bout de code qui permet de bouger le code à l’adresse 0x10000, si ce n’est pas déjà le cas et cela doit être fait avant de commencer à exécuter le reste de notre code.
</p>
</div>
</div>

<div id="outline-container-sec-6" class="outline-2">
<h2 id="sec-6"><span class="section-number-2">6</span> ELF Format</h2>
<div class="outline-text-2" id="text-6">
<p>
<code>What is the ELF format?</code>
→ D’après Wikipedia (<a href="https://fr.wikipedia.org/wiki/Executable_and_Linkable_Format">https://fr.wikipedia.org/wiki/Executable_and_Linkable_Format</a> ) :
Chaque fichier ELF est constitué d'un en-tête fixe, puis de segments et de sections. Les segments contiennent les informations nécessaires à l'exécution du programme contenu dans le fichier, alors que les sections contiennent les informations pour la résolution des liens entre fonctions et le replacement des données. 
</p>

<p>
<code>Why is it used as an object file format and an executable file format.</code>
 Il est utilisé comme executable par qemu par exemple qui est capable de comprendre le code qui est représenté à l’intérieur, mais il est est aussi utilisé comme fichier objet par objcopy pour être traduit en binaire afin de pouvoir être éxécuté sur la board.
</p>


<p>
<code>How does the ELF executable contain debug information? Which option</code>
<code>must be given to the compiler and linker? Why to both?</code>
En faisant arm-none-eabi-objdump -D kernel.elf j’ai vu les sections “.debug<sub>line”</sub> “.debug<sub>info”</sub> “.debug<sub>abbrev”</sub> “.debug<sub>aranges”</sub> “.debug<sub>str”</sub> “.debug<sub>frame”</sub>, j’imagine que ces sections sont celles qui ont été généré à la compilation grâce à l’option “-g” donné à gcc.
Il y a une option donné au linker pour avoir des infos de debug ? Il me semble que les sections que j’ai décris plus haut sont déjà présentes dans les .o, le linker script ne fait que prendre tout le contenu des .o.
</p>

<p>
<code>Confirm what ELF object files and the final ELF executable are with the</code>
<code>shell command ”file”.</code>
Il y a deux fichiers ELF ? 
$ file kernel.elf
kernel.elf: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), statically linked, with debug<sub>info</sub>, not stripped
Le fichier est bien reconnu comme un executable.
</p>

<p>
<code>Look at the ELF object files and the final ELF executable with the tool:</code>
<code>arm-none-eabi-objdump.</code>
→ fait, utilisé pour répondre et comprendre les questions d’avant
</p>
</div>
</div>

<div id="outline-container-sec-7" class="outline-2">
<h2 id="sec-7"><span class="section-number-2">7</span> Startup Code</h2>
<div class="outline-text-2" id="text-7">
<p>
<code>Read and understand the startup code in the file ”startup.s”.</code>
<code>Explain here what it does.</code>
</p>

<p>
Ce morceau de code regarde l’endroit en mémoire ou est chargé ce programme (<sub>load</sub>), et si cette adresse est différente de _start le code est déplacé à _start
</p>
</div>
</div>

<div id="outline-container-sec-8" class="outline-2">
<h2 id="sec-8"><span class="section-number-2">8</span> Main Code</h2>
<div class="outline-text-2" id="text-8">
<p>
Read and understand the main code in the file ”main.c”.
Explain here what it does. In particular, explains how the characters you
type in the terminal window actually appear on the terminal window.
With a regular shell, the shell echoes the character as you type them. It
only sends the characters once you hit the return key, as a complete line.
It is the behavior you notice here?
Dans main.c il y a : 
        une fonction qui permet d’afficher un caractère sur la sortie standard
        une fonction qui utilise la précédente pour affciher une chaine de caractère
        Une fonction qui récupère des caractères sur l’entrée standard
Le point d’entrée du programme est définit comme étant la fonction c<sub>entry</sub>() dans le linker script, cette fonction boucle indéfiniment sur une portion de code qui :
        tous les 50 millions de tours de boucle affichage du message “Zzzz….” pour montrer à l’utilisateur que le programme tourne toujours.
        S’il y a eut une entrée saisie par l’utilisateur sur l’entrée standard : affichage sur la sortie standard, sinon rien.
</p>
</div>

<div id="outline-container-sec-8-1" class="outline-3">
<h3 id="sec-8-1"><span class="section-number-3">8.1</span> What is an UART and a serial line?</h3>
<div class="outline-text-3" id="text-8-1">
<p>
UART = un composant physique qui transforme un signal electrique en bit.
ligne serie = la ou circule les bits de données
</p>
</div>
</div>

<div id="outline-container-sec-8-2" class="outline-3">
<h3 id="sec-8-2"><span class="section-number-3">8.2</span> What is the purpose of a serial line here?</h3>
<div class="outline-text-3" id="text-8-2">
<p>
Pour permettre la communication avec la board pour obtenir des entrées / fournir des sorties (saisies clavier/ affichage à l’écran).
</p>
</div>
</div>

<div id="outline-container-sec-8-3" class="outline-3">
<h3 id="sec-8-3"><span class="section-number-3">8.3</span> What is the relationship between this serial line and the Terminal window</h3>
<div class="outline-text-3" id="text-8-3">
<p>
running a shell on your laptop?
Le terminale remplace la ligne série : c’est par le terminal que l’on passe pour donner les entrées clavier à qemu, et c’est ici que s’affiche ce que qemu renvoie
</p>
</div>
</div>

<div id="outline-container-sec-8-4" class="outline-3">
<h3 id="sec-8-4"><span class="section-number-3">8.4</span> What is the special testing of the value 13 as a special character and why do we send back ’\r’ and ’\n’ ?</h3>
<div class="outline-text-3" id="text-8-4">
<p>
        Caractère 13 sur la table ASCII = carriage return : c’est pour afficher un retour à la ligne sur le terminal quand on appuie sur la touche “entrée”.
Car quand la simulation de la board renvoie /n c’est ensuite interprété par notre terminal qui comprend que cela correspond a descendre d’une ligne, et /r pour revenir à la colonne 0
</p>
</div>
</div>

<div id="outline-container-sec-8-5" class="outline-3">
<h3 id="sec-8-5"><span class="section-number-3">8.5</span> Why can we say this program polls the serial line? Although it works,why is it not a good idea?</h3>
<div class="outline-text-3" id="text-8-5">
<p>
Car ce programme lit en boucle sur la ligne série dans une boucle infinie, ce n’est pas une bonne idée car les capacités de calcul sont utilisées pour une attente active de contenue sur la ligne série.
</p>
</div>
</div>

<div id="outline-container-sec-8-6" class="outline-3">
<h3 id="sec-8-6"><span class="section-number-3">8.6</span> How could using hardware interrupts be a better solution?</h3>
<div class="outline-text-3" id="text-8-6">
<p>
Ceci permet au système de se mettre en pause jusqu’a ce qu’il recoive un signal : moindre consommation énergietique.
</p>
</div>
</div>




<div id="outline-container-sec-8-7" class="outline-3">
<h3 id="sec-8-7"><span class="section-number-3">8.7</span> Could we say that the function uart send may block? Why?</h3>
<div class="outline-text-3" id="text-8-7">
<p>
        Cela peut bloquer si le buffer de transmission est plein
Ligne de code suivante :
        while (*uart<sub>fr</sub> &amp; UART<sub>TXFF</sub>);
</p>
</div>
</div>

<div id="outline-container-sec-8-8" class="outline-3">
<h3 id="sec-8-8"><span class="section-number-3">8.8</span> Could we say that the function uart receive is non-blocking? Why?</h3>
<div class="outline-text-3" id="text-8-8">
<p>
C’est non bloquant car s’il n’y a rien a récupérer : on renvoie 0, sinon on renvoie 1 et ce qui a été saisie est stoqué dans la variable pointé par le pointeur donné en paramètre.
</p>
</div>
</div>

<div id="outline-container-sec-8-9" class="outline-3">
<h3 id="sec-8-9"><span class="section-number-3">8.9</span> Explain why uart send is blocking and uart receive is non-blocking.</h3>
<div class="outline-text-3" id="text-8-9">
<p>
La fonction d’envoie est bloquante car le programme fait envoyer au processeur des bits d’informations à l’uart, on est donc limité par le buffer de transmission
La fonction uart receive est non bloquante car elle lit sur le buffer de réception de l’uart, s’il est vide on n’a pas récupéré de donnée, sinon on en récupère, ceci sans blocage possible
</p>
</div>
</div>
</div>

<div id="outline-container-sec-9" class="outline-2">
<h2 id="sec-9"><span class="section-number-2">9</span> Test Code</h2>
<div class="outline-text-2" id="text-9">
</div><div id="outline-container-sec-9-1" class="outline-3">
<h3 id="sec-9-1"><span class="section-number-3">9.1</span> Blocking Uart-Receive</h3>
<div class="outline-text-3" id="text-9-1">
<p>
Change the code so that the function uart receive is blocking.
Why does it work in this particular test code?
Why would it be an interesting change in this particular setting?
J’ai écris une fonction “uart<sub>receive</sub><sub>blocking”</sub> similaire à la fonction “receive” de base en mettant une boucle while similaire à la fonction “send”.
Je ne vois pas particulièrement pourquoi c’est plus intéressant, ni ce qui fait que que cela la marche en particulier dans notre code de test
</p>
</div>
</div>

<div id="outline-container-sec-9-2" class="outline-3">
<h3 id="sec-9-2"><span class="section-number-3">9.2</span> Adding Printing</h3>
<div class="outline-text-3" id="text-9-2">
<p>
We provided you with the code of a kernel-version of printf, the function called
”kprintf” in the file ”kprintf.c”.
Add it to the makefile so that it is compiled and linked in.
J’ai modifié le makefile, et crée in fichier kprintf.h que j’ai inclue dans main.c
</p>

<p>
Look at the function ”kprintf” and ”putchar” in the file ”kprintf.c”. Why is
the function ”putchar” calling the function ”uart send”?
Car c’est la fonction qui permet d’envoyer un caractère vers la sortie standard
</p>

<p>
Use the function kprintf to actually print the code of the characters you type
and not the characters themselves.
Hit the following special keys:
• left and right arrow.
• backspace and delete key.
Explain what you see.
Fleche gauche : 27 + 91 + 68 ( ESC + [ + D )
fleche droite : 27 + 91 + 67 ( ESC + [ + C )
backspace : 127 ( DEL)
delete : 51 + 126  ( 3 + ~ )
On voit que les flèches de gauche et de droite ainsi que la touche delete sont interprêtés : la board renvoie plusieurs caractères pour les représenter 
</p>
</div>
</div>

<div id="outline-container-sec-9-3" class="outline-3">
<h3 id="sec-9-3"><span class="section-number-3">9.3</span> Line editing</h3>
<div class="outline-text-3" id="text-9-3">
<p>
The idea is now to allow the editing of the current line:
• Using the left and right arrows
• Using the ”backspace” and ”delete” keys
First, experiment using the left/right arrows&#x2026; and the backspace/delete
keys&#x2026;
• Explain what you see
• Explain what is happening?
Now that you understand, write the code to allow for line editing.
</p>

<p>
(je passe cette partie pour le moment afin de pouvoir passer à la suite j’y reviendrai plus tard)
</p>
</div>
</div>
</div>

<div id="outline-container-sec-10" class="outline-2">
<h2 id="sec-10"><span class="section-number-2">10</span> Laboratory Log</h2>
<div class="outline-text-2" id="text-10">
</div><div id="outline-container-sec-10-1" class="outline-3">
<h3 id="sec-10-1"><span class="section-number-3">10.1</span> Interruptions handling :</h3>
<div class="outline-text-3" id="text-10-1">
</div><div id="outline-container-sec-10-1-1" class="outline-4">
<h4 id="sec-10-1-1"><span class="section-number-4">10.1.1</span> Ce que j’ai compris du chapitre “Processor modes” et “Exceptions” de la doc de l’architecture ARMv5 :</h4>
<div class="outline-text-4" id="text-10-1-1">
<p>
        De base le processeur execute le programme en mode “user” (ou “Supervisor” étant donné que notre programme “remplace l’os” ), 
c’est à nous de la faire passer dans un autre mode dit “privilégié” ou “mode d’exception” pour avoir accès à d’autres ressources sur le matériel physique depuis le programme. 
Nous voulons donc passer en mode d’éxécution IRQ pour pouvoir gérer l’évenement externe au système “un caractère est tapé au clavier et arrive par la ligne série”.
Quand une exception est levée, l’execution du processeur est forcé sur une adresse donnée (appellé “exception vector”) en fonction de quel type d’exception il s’agit :
 pour une exception IRQ c’est l’adresse à laquelle la fonction <b>_irq<sub>handler</sub></b> qui nous est fournit dans "exceptions.s" se trouve.
</p>

<p>
Les interruptions sont désactivées quand le bit “I” dans le registre CPSR est a 1, s’il est à 0 ARM va regarder s’il y a des “regular interruption request”.
On nous donne une fonction (<b>_irqs<sub>enable</sub></b>) qui se charge de modifier le CPSR.
</p>

<p>
Le CPSR (Current Program Status Register) est un registre particulier qui contient : l’état de certains flags, le mode de processeur courrant, et d’autres informations de status et de contrôle 
Le SPSR (Saved Program Status Register) est un registre qui sert a sauvegarder l’état du CPSR en cas de gestion d’une exception.
</p>

<p>
Certains registre ne sont pas “partagés” entre les différents mode de processeur, par exemple en mode IRQ les registres 13 et 14 (stack register et linker register) ne sont pas les mêmes qu’en mode Supervisor par exemple.
</p>

<p>
Le processeur ne peut gérer qu’une seule interruption à la fois (on se limite à cela dans notre cas du moins)
</p>

<p>
Il y a un registre spécial (UART Masked Interrupt Status Register) qui indique selon la valeur qu’il contient,
 s’il y a une exception autorisées de l’UART qui est levée. Registre en read-only.
Il y a un registre le (UART Interrupt Mask Set/Clear Register) qui indique si l’UART est autorisé à lever des exceptions.
 Registre read/write : on peut modifier ici si on autorise les exceptions de l’UART en changeant un bit particulier dans ce mask.
</p>

<p>
Il y a également un registre pour indiquer que l’on a finit de traiter l’exception de l’UART (UART Interrupt Clear Register), 
il faut y écrire 1 pour indiquer que l’on a terminé de traiter l’interruption.
Il est nécessaire de dire à l’UART que l’on a finit de traiter son exception pour qu’il puisse de nouveau en lever une quand il en aura besoin.
</p>

<p>
Donc pour pouvoir gérer les exceptions sur notre board et pouvoir les utiliser dans notre contexte il faut dans un premier temps changer des paramètres contenus dans des registres spéciaux afin que le système détecte les exceptions levé par l’UART quand un caractère est tapé au clavier.
Il faut faire le nécéssaire pour que le processeur passe en mode “IRQ” quand une telle exception est levée, afin de traiter l’exception.
Il faut appeler la fonction _wfi depuis notre programme C pour endormir le processeur quand cela est nécéssaire.
Il faut définir une structure de donnée qui sera remplie par les caractères tapé au clavier
La pile n’étant pas la même (registre r13) quand le processeur est en mode “IRQ” que quand il est en mode “Supervisor”, il faut définir dans le linker script un espace mémoire pour cette nouvelle pile, 
et faire le paramétrage du mode IRQ pour que r13<sub>IRQ</sub> pointe sur cet espace mémoire.
</p>

<p>
La partie “ISR” (Interrupt Service Routine) est lancé par “<sub>irq</sub><sub>handler”</sub> en fonction de qui a levé une exception IRQ, dans notre cas on le lancera quand l’UART aura levé son exception.
ISR gerera donc la manière dont l’exception est traitée, dans notre cas : 
lecture des caractères au niveau de l’UART et remplissage du buffer circulaire tant qu’il y a des caractères / tant qu’il y a de la place dans le buffer
Il faut ensuite faire des manipulations sur des registres particuliers pour dire à l’UART qu’on a finit de traiter son exception,
 l’exécution du processeur repasse en mode “Supervisor” et notre programme principal va reprendre son execution normale :
 lire dans le buffer les caractères qui ont été mit pour les affiché à l’écran. 
(les dites manipulation sur ces registres sont inutiles : quand on lit un caractère sur la fifo de l’UART il y une détection comme quoi l’interruption a été traitée).
</p>
</div>
</div>


<div id="outline-container-sec-10-1-2" class="outline-4">
<h4 id="sec-10-1-2"><span class="section-number-4">10.1.2</span> Ce que j'ai mis en place dans le code</h4>
<div class="outline-text-4" id="text-10-1-2">
</div><ol class="org-ol"><li><a id="sec-10-1-2-1" name="sec-10-1-2-1"></a>UART<br  /><div class="outline-text-5" id="text-10-1-2-1">
<div class="org-src-container">

<pre class="src src-c">/*
 * uart.h
 *
 *  Created on: Jan 26, 2021
 *      Author: Francois Robert
 */

#ifndef UART_H_
#define UART_H_

//#include &lt;stddef.h&gt;

/**
 * Look at the document describing the Versatile Application Board:
 *
 *    Versatile Application Baseboard for ARM926EJ-S (HBI-0118)
 *
 * Also referenced as DUI0225, downloadable from:
 *
 *  http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0225d/I999714.html
 *
 * Look at the memory map, section 4.1, page 137, to find the base addresses for all
 * the devices. We only use here the UARTs.
 */
#define UART0 0x101f1000
#define UART1 0x101f2000
#define UART2 0x101f3000

/**
 * PL011_T UART
 *     http://infocenter.arm.com/help/topic/com.arm.doc.ddi0183f/DDI0183.pdf
 *
 * UARTDR: Data Register   (0x00)
 *    To read received bytes
 *    To write bytes to send
 *    Bit Fields:
 *      15:12 reserved
 *      11:08 error flags
 *       7:0  data bits
 * UARTFR:  Flag Register  (0x18)
 *    Bit Fields:
 *      7:  TXFE  transmit FIFO empty
 *      6:  RXFF  receive FIFO full
 *      5:  TXFF  transmit FIFO full
 *      4:  RXFE  receive FIFO empty
 *      3:  BUSY  set when the UART is busy transmitting data
 */

#define UART_DR 0x00
#define UART_FR 0x18

#define UART_TXFE (1&lt;&lt;7)
#define UART_RXFF (1&lt;&lt;6)
#define UART_TXFF (1&lt;&lt;5)
#define UART_RXFE (1&lt;&lt;4)
#define UART_BUSY (1&lt;&lt;3)

/**
 * Receive a character from the given uart, this is a non-blocking call.
 * Returns 0 if there are no character available.
 * Returns 1 if a character was read.
 */
int uart_receive(int uart, unsigned char *s);

/**
 * Receive a character from the given uart, this is a blocking call.
 * Returns 1 when a character was read.
 */
int uart_receive_blocking(int uart, unsigned char *s) ;

/**
 * Sends a character through the given uart, this is a blocking call.
 * The code spins until there is room in the UART TX FIFO queue to send
 * the character.
 */
void uart_send(int uart, unsigned char s);

/**
 * This is a wrapper function, provided for simplicity,
 * it sends a C string through the given uart.
 */
void uart_send_string(int uart, const unsigned char *s);

#define UART0IMSC UART0+0x38 // l'adresse du registre UART_IMSC de l'uart 0 (doc de l'UART)
#define RXIM (1&lt;&lt;4) //le 4ème bit du registre UARTIMSC : Receive interrupt mask (doc de l'UART)
#define UART0ICR UART0+0x44 //l'adresse du registre UART_ICR de l'uart 0 (doc de l'UART)
#define RXIC (1&lt;&lt;4) //le 4ème bit du registre UART_ICR : Receive interrupt clear (doc de l'UART)

#define VIC_BASE_ADDRESS 0x10140000 //adresse de base du VIC (trouvé dans la doc de la board : chapitre "interrupt controllers")
#define VICINTENABLE 0x10140010 //l'adresse du registre VICINTENABLE (trouvé sur la doc du VIC )
#define VICIRQSTATUS VIC_BASE_ADDRESS+0x000//l'adresse du registre VICIRQSTATUS (trouvé sur la doc du VIC )
#define VIC_UART0_LINE (1&lt;&lt;12) //Doc de la board section sur l'UART : il est dit que pour UART 0 c'est le 12ème bit pour les interruptions

#define UART0_IRQ 12

/*
     Cette fonction est appelée pour répondre à une exception levée par l'UART0 :
     - Il faut d'abord récupérer les caractères au niveau de l'UART tant qu'il y en a pour
     remplir le buffer circulaire (ou jusqu'a ce que le buffer soit plein)
     - Il faut une fois finit mettre 1 dans le registre UART Interrupt Clear, pour dire à
     l'UART que l'on a finit de traiter son exception pour qu'il puisse en lever de nouveau s'il en a besoin (Se fait tout seul si on lit dans la FIFO)
*/
void uart0_isr();

//TODO :
int read_buffer(char* c);

#endif /* UART_H_ */
</pre>
</div>
</div>
</li>

<li><a id="sec-10-1-2-2" name="sec-10-1-2-2"></a>ISR<br  /><div class="outline-text-5" id="text-10-1-2-2">
<div class="org-src-container">

<pre class="src src-c">/*
     Cette fonction est appelé par la fonction _irq_handler de exception.s :
     Quand le PIC demande au processeur de traiter une exception IRQ, et que le 
     processeur décide de la traiter, on arrive ici.
     - Il faut donc commencer par savoir quelle est la source de l'exception,
     si c'est l'UART0 (celui odnt on veut s'occuper ici) on appelle la routine
     associée afin de traiter l'exception.  
*/
void irq_handler();

/* 
Cette fonction est appelé au lancement de notre "kernel", elle permet de 
mettre en place tout ce qui est nécessaire à la gestion des exceptions IRQ :
- Il faut autoriser l'UART a lever des exceptions :
-&gt; Pour ce faire : voir dans la doc de la board l'adresse du registre UART IMSC 0
et voir quel bit il faut mettre à 1 pour signifier que l'UART0 peut lever des exceptions IRQ
- Il faut définir l'adresse de la pile (stack) que notre programme va utiliser quand il sera
en mode IRQ (les différents mode de processeur ne partageant pas tous les registres,
c'est le cas ici pour r13 (le stack-pointer) et r14 (le link register) par ex ) :
-&gt; Pour ce faire : appel a la fonction _irqs_setup qui nous est fournie. 
(Note : il a fallut définir dasn le linker script un espace pour cette nouvelle stack)
- Il faut initialiser un buffer circulaire dans lequel on va mettre les caractères 
que l'on peut lire dans l'UART0
-&gt; Pour ce faire on implémente une structure de buffer circulaire et on l'instancie en mémoire
- Il faut autoriser l'UART0 à lever des exceptiosn au niveau du PIC :
-&gt; Pour ce faire je sais pas encore (voir doc) mais il faut passer un bit a 1 dans un mask (VICINTENABLE ou VICINTENCLEAR)
*/
void irqs_setup();

/*
Cette fonction autorise les exceptions au niveau du processeur 
en modifiant le CPSR. Le code est fournie dans la fonction _irqs_enable
dans exceptions.s. 
*/
void irqs_enable();

/*
Cette fonction désactive les exceptions au niveau du processeur 
en modifiant le CPSR. Le code est fournie dans la fonction _irqs_enable
dans exceptions.s.
Pendant que le processeur ne gère plus les exceptions, le PIC lui continue 
de le faire, ainsi, si on réactive les exceptions le processeur gerera les 
exceptions qui ont été mise "en attente " le temps ou les exceptions étaient
désactivés à ce niveau.
*/
void irqs_disable();

/* Cette fonction est appelée lorsqu'une exception à été levée et que le processeur est passée en mode IRQ
- Il faut renvoyer un entier qui permet d'identifier qui a levé l'exception
*/
int pic_next_raised_irq();
</pre>
</div>
</div>
</li>

<li><a id="sec-10-1-2-3" name="sec-10-1-2-3"></a>Makefile<br  /><div class="outline-text-5" id="text-10-1-2-3">
<p>
j’ai ajouté les règles de compilation nécessaire au makefile puis changé les includes dans les fichiers concernés.
</p>
</div>
</li>

<li><a id="sec-10-1-2-4" name="sec-10-1-2-4"></a>Linker Script<br  /><div class="outline-text-5" id="text-10-1-2-4">
<p>
J’ai aussi ajouté la déclaration d'une stack pour le mode IRQ dans le linker script
</p>
<pre class="example">
/* 
  * Reserve some memory for the C stack
  * for irq 
  */
 . = ALIGN(8);
 . = . + 0x1000; /* 4kB of stack memory */
 irq_stack_top = .;
</pre>
</div>
</li>

<li><a id="sec-10-1-2-5" name="sec-10-1-2-5"></a>Structure de donnée pour échanger en le mode <b>IRQ</b> et le mode <b>Supervisor</b><br  /><div class="outline-text-5" id="text-10-1-2-5">
<p>
j'ai implémenté un buffer circulaire :
</p>
<div class="org-src-container">

<pre class="src src-c">//On définit le buffer circulaire dont on se sert pour communiquer entre le mode IRQ et le programme principal
#define MAX_CHARS 256
volatile char buffer[MAX_CHARS];
volatile int head = 0;
volatile int tail = 0;
</pre>
</div>

<p>
Pour ecrire dans le buffer
</p>
<div class="org-src-container">

<pre class="src src-c" id="ecriture-buffer">char code;
  int is_next = uart_receive(UART0,&amp;code);
  while (is_next) {
    int next = (head + 1) % MAX_CHARS;
    if (next==tail) //si le buffer est plein
      return; 
    //sinon on ajoute le caractère
    buffer[head] = code;
    head = next;
    is_next = uart_receive(UART0,&amp;code);
  }
</pre>
</div>

<p>
Pour lire dans le buffer
</p>
<div class="org-src-container">

<pre class="src src-c" id="lecture-buffer">if (head == tail)
    return 0;
  else {
    *c = buffer[tail];
    tail++;
    return 1;
  }
</pre>
</div>
</div>
</li>

<li><a id="sec-10-1-2-6" name="sec-10-1-2-6"></a>Programme principal<br  /><div class="outline-text-5" id="text-10-1-2-6">
<p>
j'ai modifié le code de la fonction main:
</p>

<div class="org-src-container">

<pre class="src src-c">void c_entry() {
  irqs_setup();
  uart_send_string(UART0, "\nHello world!\n");
  uart_send_string(UART0, "\nQuit with \"C-a c\" and then type in \"quit\".\n");
   int eol = 0;
   char c;
    for (;;) {
        eol=read_buffer(&amp;c);
        if (eol) {
            kprintf("%c", c);
        }
        _wfi();
    }
}
</pre>
</div>



<p>
Pour plus de détails on peut consulter le code produit à l’adresse suivante : 
<a href="https://github.com/Robert-Fr/M2M/tree/master/Step0/workspace/arm.boot">https://github.com/Robert-Fr/M2M/tree/master/Step0/workspace/arm.boot</a>
</p>
</div>
</li></ol>
</div>
</div>


<div id="outline-container-sec-10-2" class="outline-3">
<h3 id="sec-10-2"><span class="section-number-3">10.2</span> Linux Distribution :</h3>
<div class="outline-text-3" id="text-10-2">
</div><div id="outline-container-sec-10-2-1" class="outline-4">
<h4 id="sec-10-2-1"><span class="section-number-4">10.2.1</span> Minidist directory</h4>
<div class="outline-text-4" id="text-10-2-1">
<p>
Dans le répertoire minidist il y a tout ce qu'il faut pour booter sur notre mini distribution :
il y a deux images compressé du kernel linux et leurs deux configurations de build respectives
il y a initrd.hello 
grub ( le boot loader)
</p>

<p>
Au boot de la machine, le BIOS charge le boot loader en mémoire à l'adresse 0x7c00.
Il passe l'éxécution au boot loader (ici le stage 1 de GRUB)
Grub va charger le kernel qui est aussi dans le répertoire minidist (un des deux en fonction du choix que l'on fait dans le menu )
</p>
</div>
</div>

<div id="outline-container-sec-10-2-2" class="outline-4">
<h4 id="sec-10-2-2"><span class="section-number-4">10.2.2</span> GRUB Bootloader</h4>
<div class="outline-text-4" id="text-10-2-2">
<p>
l'option du kernel "root=XXX" indique au kernel ou charger le répertoire racine 
</p>

<p>
Hello est compilé avec l'option -static de gcc : ceci explique pourquoi les fichiers résultant de la compilation sont très lourds : il n'y a pas de lien dynamique vers des librairies extérieurs.
L'executable obtenue contient le code en statique de toutes les modules extérieurs qu'il utilise, utile ici car on n'a pas inclu de librairies exterieurs dans notre mini distribution.
</p>


<p>
initrd.hello = mise en place d'un répertoire racine temporaire minimal en mémoire ( d'ou root=/dev/ram) 
</p>
</div>
</div>

<div id="outline-container-sec-10-2-3" class="outline-4">
<h4 id="sec-10-2-3"><span class="section-number-4">10.2.3</span> Minimal File-System Layout</h4>
<div class="outline-text-4" id="text-10-2-3">
<p>
Je n'ai pas fait cette partie
</p>
</div>
</div>

<div id="outline-container-sec-10-2-4" class="outline-4">
<h4 id="sec-10-2-4"><span class="section-number-4">10.2.4</span> The "init" process</h4>
<div class="outline-text-4" id="text-10-2-4">
<p>
le programme "hello" est un executable autonome grace a l'option -static de gcc. 
l'executable est gros car contient le code de toutes libs exterieurs qu'il utilise en statique.
C'est nécessaire dasn notre cas car on a pas de librairie inclue dans notre petite distribution,
donc obligé sinon il ne connait pas printf etc par exemple. 
</p>

<p>
J'ai enlevé l'option -static de CFLAGS dans le makefile : 
$ make
$ ldd hello
&gt; linux-gate.so.1 (0xf7f8f000)
&gt; libc.so.6 =&gt; /lib/i386-linux-gnu/libc.so.6 (0xf7d95000)
&gt; /lib/ld-linux.so.2 (0xf7f90000)
</p>

<p>
j'ai mis les librairies prises dans "debian-initrd" dans Minidist/lib
Le boot fonctionne quand je boot depuis le disque, pas avec initrd.
Je pense que cela vient du fait que les librairies que j'ai mis sous /lib ne sont pas contenue dans initrd.hello.
Pour que cela marche il faudrait modifier le makefile pour qu'il ne contienne pas que le programme hello, mais aussi les librairies dont le programme a besoin ?
</p>
</div>
</div>


<div id="outline-container-sec-10-2-5" class="outline-4">
<h4 id="sec-10-2-5"><span class="section-number-4">10.2.5</span> The shell Setup</h4>
<div class="outline-text-4" id="text-10-2-5">
</div><ol class="org-ol"><li><a id="sec-10-2-5-1" name="sec-10-2-5-1"></a>The script "init"<br  /><div class="outline-text-5" id="text-10-2-5-1">
<p>
j'ai mis le script "init" sous Minidist/init et changé les entrées dans le menu de GRUB.
Cela ne fonctionne pas car il n'y a pas de shell défini dans notre distributions pour le moment&#x2026;
Je me suis arrêté la.
</p>
</div>
</li></ol>
</div>
</div>
</div>
</div>
<div id="postamble" class="status">
<p class="author">Auteur: Francois Robert</p>
<p class="date">Created: 2021-02-15 Mon 18:38</p>
<p class="creator"><a href="http://www.gnu.org/software/emacs/">Emacs</a> 25.2.2 (<a href="http://orgmode.org">Org</a> mode 8.2.10)</p>
<p class="validation"><a href="http://validator.w3.org/check?uri=referer">Validate</a></p>
</div>
</body>
</html>
