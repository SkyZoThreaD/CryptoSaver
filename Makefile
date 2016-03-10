.PHONY: clean All

All:
	@echo "----------Building project:[ cryptosaverd - Release ]----------"
	@cd "cryptosaverd" && "$(MAKE)" -f  "cryptosaverd.mk"
clean:
	@echo "----------Cleaning project:[ cryptosaverd - Release ]----------"
	@cd "cryptosaverd" && "$(MAKE)" -f  "cryptosaverd.mk" clean
