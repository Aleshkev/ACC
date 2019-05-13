===
ACC
===


.. TODO: This shows three 'cyclical reference' warnings, but I can't get it to
   work any other way.
.. toctree::
   index


Główny Szablon
==============
.. literalinclude:: src/template.cpp

Przechodzenie grafu
===================

DFS, iteracyjnie
----------------

.. literalinclude:: src/bfs_dfs.cpp
   :start-after: <dfs-iterative>
   :end-before: </dfs-iterative>
   :dedent: 4

DFS, rekurencyjnie
------------------
.. literalinclude:: src/bfs_dfs.cpp
   :start-after: <dfs-recursive>
   :end-before: </dfs-recursive>
   :dedent: 4

BFS, iteracyjnie
----------------
.. literalinclude:: src/bfs_dfs.cpp
   :start-after: <bfs-iterative>
   :end-before: </bfs-iterative>
   :dedent: 4


Wyszukiwanie Binarne
====================

Funkcja f-search
----------------
.. literalinclude:: src/bin_search.cpp
   :start-after: <f-search>
   :end-before: </f-search>


Drzewa Przedziałowe
===================

Drzewa używają functorów:

.. literalinclude:: src/segment_tree.cpp
   :start-after: <example-functors>
   :end-before: </example-functors>

Punkt-Przedział
---------------
.. literalinclude:: src/point_tree.cpp
   :start-after: <point-segment-tree>
   :end-before: </point-segment-tree>

Przedział-Przedział
-------------------
.. literalinclude:: src/segment_tree.cpp
   :start-after: <segment-segment-tree>
   :end-before: </segment-segment-tree>


Drzewo Potęgowe
===============

Także Fenwick Tree lub Binary Indexed Tree (BIT).

.. literalinclude:: src/fenwick_tree.cpp
   :start-after: <fenwick-tree>
   :end-before: </fenwick-tree>


Manacher
========

.. literalinclude:: src/manacher.cpp
   :start-after: <manacher>
   :end-before: </manacher>


Hasze
=====

Hasze używają functorów do modulo. Dzięki Kubinowi dostępne jest `modulo przez liczby pierwsze Mersenne'a <https://kubin.w.staszic.waw.pl/sheets/of-modulo.html>`_. 

.. literalinclude:: src/string_hashing.cpp
   :start-after: <mod-functors>
   :end-before: </mod-functors>

.. literalinclude:: src/string_hashing.cpp
   :start-after: <hash-models>
   :end-before: </hash-models>


Operacje bitowe
===============

Przeciwne znaki?
----------------
.. literalinclude:: src/bit_operations.cpp
   :start-after: <opposite-signs>
   :end-before: </opposite-signs>

Następna maska bitowa
---------------------
.. literalinclude:: src/bit_operations.cpp
   :start-after: <next-permutation>
   :end-before: </next-permutation>


Szybkie IO
==========

.. literalinclude:: src/fast_io.cpp
   :start-after: <fast-io>
   :end-before: </fast-io>
