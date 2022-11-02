ORIGIN=git@vogsphere.42lausanne.ch:vogsphere/intra-uuid-456b369f-9e45-4a5f-9c00-2077af2ba7bc-4498546-skoulen
AUTHORIZED_FILES= get_next_line.h get_next_line.c get_next_line_utils.c
PATH_RENDU= ~/cursus42/rendu/get_next_line

all: update-rendu

copy:
	for file in $(AUTHORIZED_FILES) ; do\
		cp src/$$file $(PATH_RENDU); \
	done
init:
	cd $(PATH_RENDU)
	git init
	git remote remove origin
	git remote add origin $(ORIGIN)
	git add .
	git commit -m "first commit"
	git push origin master

update:
	cd $(PATH_RENDU)
	git add .
	git commit -m "$(date +'%Y-%m-%d')"
	git push origin master

create-rendu: copy init
update-rendu: copy update

