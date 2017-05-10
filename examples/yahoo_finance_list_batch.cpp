//
// Created by jmkim on 5/11/17.
//

#include <cstdio>
#include <cstring>
#include "../src/RetrieveData.hpp"

#define MAX_LINE_LENGTH 500

int main ()
{
  std::FILE *fp_list = std::fopen ("list.csv", "r");
  while (std::feof (fp_list) == 0)
    {
      char line[MAX_LINE_LENGTH] = {0,};
      {
        int i, ch;
        for (i = 0; (ch = std::fgetc (fp_list)) != '\n' && std::feof (fp_list) == 0; ++i)
          { line[i] = (char) ch; }
        if (std::strlen (line) <= 0)
          { break; }
      }

      char item_name[10];
      {
        char item_num[7] = {0,};
        int i;
        for (i = 0; line[i] != ','; ++i)
          { item_num[i] = (char) line[i]; }

        std::sprintf (item_name, "%06d.KQ", std::atoi (item_num));
      }

      char csv_in[FILENAME_MAX];
      char csv_out[FILENAME_MAX];
      {
        std::sprintf (csv_in, "./csv/%s.csv", item_name);
        std::sprintf (csv_out, "./csv_out/%s.csv", item_name);
      }

    JUMP_RETRY:
    stock_crawler::RetrieveDataFromYahooFinance (item_name, "1399474800", "1494169200", "1d", csv_in);

      std::FILE *fp_csv_in = std::fopen (csv_in, "r");
      if (std::fgetc (fp_csv_in) == '{')
        {
          if (std::fgetc (fp_csv_in) == '"')
            {
              std::fprintf (stderr, "Warning: Reported as invalid range. Ignoring... (item name: %s)\n", item_name);
              continue;
            }
          else
            {
              std::fprintf (stderr, "Warning: 401 Unauthorized. Retrying... (item name: %s)\n", item_name);
              goto JUMP_RETRY;
            }
        }
      while (std::fgetc (fp_csv_in) != '\n');

      std::FILE *fp_csv_out = std::fopen (csv_out, "w");
      while (std::feof (fp_csv_in) == 0)
        {
          char l[MAX_LINE_LENGTH] = {0,};
          {
            int i, ch;
            for (i = 0; (ch = std::fgetc (fp_csv_in)) != '\n' && std::feof (fp_csv_in) == 0; ++i)
              { l[i] = (char) ch; }
            if (std::strlen (l) <= 0)
              { break; }
          }

          std::fprintf (fp_csv_out, "%s,%s\n", item_name, l);
        }
      std::printf ("Edited file was saved to '%s'\n\n", csv_out);
      std::fclose (fp_csv_out);
      std::fclose (fp_csv_in);
    }
  std::fclose (fp_list);
  return 0;
}
