normal:
	@ cd normal_traversal/ && $(MAKE) 

normal_clean:
	@ rm *.txt
	@ cd normal_traversal/ && $(MAKE) clean

dfs:
	@ cd dfs_traversal/ && $(MAKE)
 
dfs_clean:	
	@ rm *.txt
	@ cd dfs_traversal/ && $(MAKE) clean

