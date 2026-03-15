CXX := g++
CXXFLAGS := -std=c++17 -O2 -DLOCAL

new:
	@mkdir -p $(dir $(filter-out $@,$(MAKECMDGOALS)))
	@cp template.cpp $(filter-out $@,$(MAKECMDGOALS)).cpp
	@code $(filter-out $@,$(MAKECMDGOALS)).cpp
	@echo "Created $(filter-out $@,$(MAKECMDGOALS)).cpp"

run:
	@$(CXX) $(CXXFLAGS) $(filter-out $@,$(MAKECMDGOALS)).cpp -o a.out
	@./a.out < in.txt > out.txt 2> debug.txt
	@rm a.out
%:
	@: