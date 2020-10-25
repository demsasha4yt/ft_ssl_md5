/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:41:20 by bharrold          #+#    #+#             */
/*   Updated: 2020/10/25 19:10:50 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"
#include "sha2.h"
#include "testcases.h"

#ifdef TEST

static const t_tc g_tcs[] = {
	{
		.name = "MD5",
		.string = "Hello",
		.func = &md5_string,
		.valid = "8b1a9953c4611296a827abf8c47804d7",
	},
	{
		.name = "MD5",
		.string = "LOREM IPSUM",
		.func = &md5_string,
		.valid = "6b0e91ce2b8660a332facad2cde4c56e",
	},
	{
		.name = "MD5",
		.string = "Hello",
		.func = &md5_string,
		.valid = "8b1a9953c4611296a827abf8c47804d7",
	},
	{
		.name = "MD5",
		.string = "asdfdsfasdfasdfasdfasdfasdfasdfMy super dog",
		.func = &md5_string,
		.valid = "aa6d64dcf69a9dc126c2250ae856406a",
	},
	{
		.name = "MD5",
		.string = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",
		.func = &md5_string,
		.valid = "db89bb5ceab87f9c0fcc2ab36c189c2c",
	},
	{
		.name = "MD5",
		.string = "",
		.func = &md5_string,
		.valid = "d41d8cd98f00b204e9800998ecf8427e",
	},
	{
		.name = "MD5",
		.string = "rsfrlaiyvPTXo34HtDpNthllGOYuJnXkdI63831eJFz0csmDnZLZ8v4ESWR4nvsoGX3TNp1l2COt6XsAiglrZ3iN3OGrKJrAAHan6LaSCI0oeguo99MTXKf3KxT5JU1d2XUsGyzukP8hMeBKJoljrarcmGQkiKGbzMlsjUY7pOO4Jxe7Lp1rGizCN2UpfX5VwMSeBR4Wh452icu0uejXVvOHKX2Hm7HkFnpPF4VKugCjLMZOXbmgMCI9fvo8424y1qkUEMDk1wtwdFXYDqqiQwweKTyjKLfA6WpBdFYRtsJuUio53hXWK6kRcWeRBUSiTmg5vlqCkhDmNIP7vzzxJ4YssQkow9khHwelDLZLxNarWfUWVVSOaABZ0gpgrU1EdUoeDjR27Gl1vil4zffE3ssGFy4lzIatHiVwFc3ooD1eFOX9fTnnMyJC0w5JOKahBZa2dZt3gZYlBMg27vgYjrtfC3LJdLGdUiqPfiXXbrHyKjHBsI7qHeRur3bZ30PvItBSmPlDkipPs2mGlRhWEn7gRQfysn3uz97XJozckz0wHcsQGf4WQguE2CCY1HngeJsmoU1ClOFWekMbdDGS6n9IZbpX4jSgdfiAG9U5aDkwCHsniKJli6N5Qx5BPNOD8cbJVDXhaMlIriBF0F3ChEJmep3LXAjnMzBoKubVFGKvktrclBghz8j4zA4RM2ENydVGcy7K7KxlZIWFGP7Bi62TUDowPWbPj0MpRBTablfxkoCZ78LVfQP9GuHHquHFmV1Uvct4bPzr3Bpqx2Bm6WYzJyxbDCXZOp9zk7thWrsVsNtGie4ucQONUpeEZdXr77Hx2w6W5ei3Ke9LCtRt3olEYooCMTbWzmTNOgfgGoY7U41sTl0olE8KIorBYuwWkZSDw8mqePuyB0MUfT59GTPxh8KcNSuqyEjT7EdiKqoyvlTxv0nqEgN8qCDhZ2Usrg4YncG9UCkod2UOcj0F5MegdhZKTT29wIg0sNYq",
		.func = &md5_string,
		.valid = "8aee0cf8c5f8f9e282d093ab09a050f7",
	},
	{
		.name = "MD5",
		.string = "",
		.func = &md5_string,
		.valid = "d41d8cd98f00b204e9800998ecf8427e",
	},
	{
		.name = "MD5",
		.string = "1",
		.func = &md5_string,
		.valid = "c4ca4238a0b923820dcc509a6f75849b",
	},
	{
		.name = "MD5",
		.string = "c4ca4238a0b923820dcc509a6f75849b",
		.func = &md5_string,
		.valid = "28c8edde3d61a0411511d3b1866f0636",
	},
	{
		.name = "SHA256",
		.string = "",
		.func = &sha256_string,
		.valid = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
	},
	{
		.name = "SHA256",
		.string = "1234",
		.func = &sha256_string,
		.valid = "03ac674216f3e15c761ee1a5e255f067953623c8b388b4459e13f978d7c846f4",
	},
	{
		.name = "SHA256",
		.string = "Hello",
		.func = &sha256_string,
		.valid = "185f8db32271fe25f561a6fc938b2e264306ec304eda518007d1764826381969",
	},
	{
		.name = "SHA256",
		.string = "rsfrlaiyvPTXo34HtDpNthllGOYuJnXkdI63831eJFz0csmDnZLZ8v4ESWR4nvsoGX3TNp1l2COt6XsAiglrZ3iN3OGrKJrAAHan6LaSCI0oeguo99MTXKf3KxT5JU1d2XUsGyzukP8hMeBKJoljrarcmGQkiKGbzMlsjUY7pOO4Jxe7Lp1rGizCN2UpfX5VwMSeBR4Wh452icu0uejXVvOHKX2Hm7HkFnpPF4VKugCjLMZOXbmgMCI9fvo8424y1qkUEMDk1wtwdFXYDqqiQwweKTyjKLfA6WpBdFYRtsJuUio53hXWK6kRcWeRBUSiTmg5vlqCkhDmNIP7vzzxJ4YssQkow9khHwelDLZLxNarWfUWVVSOaABZ0gpgrU1EdUoeDjR27Gl1vil4zffE3ssGFy4lzIatHiVwFc3ooD1eFOX9fTnnMyJC0w5JOKahBZa2dZt3gZYlBMg27vgYjrtfC3LJdLGdUiqPfiXXbrHyKjHBsI7qHeRur3bZ30PvItBSmPlDkipPs2mGlRhWEn7gRQfysn3uz97XJozckz0wHcsQGf4WQguE2CCY1HngeJsmoU1ClOFWekMbdDGS6n9IZbpX4jSgdfiAG9U5aDkwCHsniKJli6N5Qx5BPNOD8cbJVDXhaMlIriBF0F3ChEJmep3LXAjnMzBoKubVFGKvktrclBghz8j4zA4RM2ENydVGcy7K7KxlZIWFGP7Bi62TUDowPWbPj0MpRBTablfxkoCZ78LVfQP9GuHHquHFmV1Uvct4bPzr3Bpqx2Bm6WYzJyxbDCXZOp9zk7thWrsVsNtGie4ucQONUpeEZdXr77Hx2w6W5ei3Ke9LCtRt3olEYooCMTbWzmTNOgfgGoY7U41sTl0olE8KIorBYuwWkZSDw8mqePuyB0MUfT59GTPxh8KcNSuqyEjT7EdiKqoyvlTxv0nqEgN8qCDhZ2Usrg4YncG9UCkod2UOcj0F5MegdhZKTT29wIg0sNYq",
		.func = &sha256_string,
		.valid = "17ed4644d56dbe0c695f115cf91bff59aa4719b854394ee10cf2366f193937d5",
	},
	{
		.name = "SHA256",
		.string = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",
		.func = &sha256_string,
		.valid = "2d8c2f6d978ca21712b5f6de36c9d31fa8e96a4fa5d8ff8b0188dfb9e7c171bb",
	},
	{
		.name = "SHA256",
		.string = "asdfdsfasdfasdfasdfasdfasdfasdfMy super dog",
		.func = &sha256_string,
		.valid = "236953951ff59353008abd58c575af3b145e4b13032b6eb050239cd202589d3a",
	},
	{
		.name = "STOP",
		.string = "\0",
		.func = NULL,
		.valid = "\0",
	}
};

int			main(void)
{
	t_tc	*tc;
	char	*result;

	tc = (t_tc*)g_tcs;
	while (tc && tc->func != NULL)
	{
		printf("[TEST]: Start %s: value=\"%s\", expected=\"%s\"\n",
			tc->name, tc->string, tc->valid);
		result = tc->func(tc->string);
		printf("[TEST]: Result=\"%s\"\n", result);
		assert(result != NULL);
		assert(!strcmp(result, tc->valid));
		free(result);
		printf("[TEST]: Ok!\n");
		tc++;
	}
	return (0);
}

#endif
