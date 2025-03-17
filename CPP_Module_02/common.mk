# common.mk

# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJDIR = bin
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))
DEP = $(OBJS:%.o=%.d)

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

-include $(DEP)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re