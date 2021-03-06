COMPILER = g++
CFLAGS   = -g -MMD -MP -O3 -Wall -Wextra -Werror -Wfatal-errors -march=native -mtune=native
LDFLAGS  = ${CFLAGS}
LIBS     =
INCLUDE  =
RUSTC    = rustc
RSFLAGS  = --crate-type="cdylib"
TARGET   = ./$(shell basename `readlink -f ..`)
OBJDIR   = ./obj
ifeq "$(strip $(OBJDIR))" ""
  OBJDIR = .
endif
SOURCES_C = $(wildcard *.cpp)
OBJECTS_C = $(addprefix $(OBJDIR)/, $(SOURCES_C:.cpp=.o))
DEPENDS  = $(OBJECTS:.o=.d)
SOURCES_RS = $(wildcard *.rs)
OBJECTS_RS = $(addprefix $(OBJDIR)/lib, $(SOURCES_RS:.rs=.so))
LDFLAGS += $(addprefix -l, $(SOURCES_RS:.rs=)) -L$(OBJDIR) -Xlinker -rpath -Xlinker $(OBJDIR)

$(TARGET): $(OBJECTS_C) $(OBJECTS_RS) $(LIBS)
	$(COMPILER) -o $@ $(OBJECTS_C) $(LIBS) $(LDFLAGS)

$(OBJDIR)/%.o: %.cpp
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(OBJDIR)/lib%.so: %.rs
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(RUSTC) $(RSFLAGS) $< -o $@

all: clean $(TARGET)

clean:
	rm -rf $(OBJDIR) $(TARGET)

-include $(DEPENDS)
