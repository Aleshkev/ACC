===
ACC
===


.. math::

   \frac{ \sum_{t=0}^{N}f(t,k) }{N}

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
