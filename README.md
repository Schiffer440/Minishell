# gen notes

- [OK] test exec 
- [OK] modif ft_exec avec char *exec unique a envoyer dans mon ft_exec(modifer le get cmds)

# exec
- [OK] exit
- [ ] mettre en place la boulce exec qui prend en compte le tab de cmds
- [ ] gerer les redirs dans la structure de cmds

# parse
- [ ] ``minishell > grep 'coucou' |   | cat main.c `` > msg erreur
### parsing env
- [ ] envp init
- [ ] envp init if not env (check what is expected before)(PWD, shell level and _)
- [ ] display env
- [ ] replace (or actualise) an env value function
- [ ] delete an env value function
- [ ] create an env value function (export)
### parsing cmd
- [ ] faire choix de struct pour le lexer ou include directement dans le parsing ?
- [ ] check if using ' "
- [ ] cas d'erreur qui fait que la commande s'arrete au parsing et non exec ?
- [ ] redirections
## parse doc links
- [is * a wildcard](https://hbctraining.github.io/Intro-to-shell-flipped/lessons/02_wildcards_shortcuts.html#:~:text=The%20Shell%20(bash)%20considers%20an,the%20most%20for%20our%20exercises.)