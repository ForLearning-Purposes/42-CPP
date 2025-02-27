# common.mk

# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJDIR = bin
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re