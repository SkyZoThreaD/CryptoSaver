.PHONY: clean All

All:
	@echo "----------Building project:[ cryptosaverd - Debug ]----------"
	@cd "cryptosaverd" && "$(MAKE)" -f  "cryptosaverd.mk"
clean:
	@echo "----------Cleaning project:[ cryptosaverd - Debug ]----------"
	@cd "cryptosaverd" && "$(MAKE)" -f  "cryptosaverd.mk" clean
