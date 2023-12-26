#include "../includes/minishell.h"

// Placez ici toutes les structures et fonctions que vous avez fournies

int main() {
    t_parse ms;
    ms.arr_token = NULL;
    ms.arr_input = NULL;
    ms.token_nb = 0;
    ms.cmds = NULL;
    ms.env_struct = NULL;
    ms.data_struct = NULL;

    char *input_str = "command1 < input.txt | command2 > output.txt";
    int result = ft_parse_input(input_str, &ms);

    if (result == R_EX_OK) {
        t_cmd *cmd_struct = ft_fill_cmd_struct(&ms);

        // Affichage des résultats pour vérification
        printf("Parsed Tokens:\n");
        for (int i = 0; i < ms.token_nb; i++) {
            printf("%s\n", ms.arr_token[i]);
        }

        printf("\nParsed Commands:\n");
        t_cmd *current_cmd = cmd_struct;
        while (current_cmd != NULL) {
            printf("Command: %s\n", current_cmd->cmd);
            printf("Previous Token: %s\n", current_cmd->prev_token);
            printf("Next Token: %s\n", current_cmd->next_token);
            printf("\n");
            current_cmd = current_cmd->next;
        }

        // Libération de la mémoire
        ft_free_all(&ms);
    } else {
        // Affichage d'une erreur si la parsing a échoué
        printf("%sParsing failed.\n", SYNTAX_ERR);
    }

    return 0;
}
