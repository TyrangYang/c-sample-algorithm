-module(ex).
-compile(export_all).

fact(0) -> 
	1;
fact(N) -> 
	N*fact(N-1).

len([]) ->
	0;
len([_H | T]) ->
	1 + len(T).

sum([]) -> 
	0;
sum([H|T]) ->
	H+sum(T).

map(_F,[])->
	[];
map(F, [H|T]) ->
	[F(H) | map(F,T)].

% foldl(F,A,[]) ->
% 	A;
% foldl(F,A,[H|T]) ->
% 	F(H,foldl(F,A,T)).

% foldr(F,A,[]) ->
% 	A;
% foldr(F,A,[H|T]) ->
% 	F(F,F(A,H),T)).

rem_adj_dupl([]) ->
	[];
rem_adj_dupl([H]) ->
	[H];
rem_adj_dupl([H1 | [H2|T] ]) when H1 == H2->
	rem_adj_dupl([H2|T]);
rem_adj_dupl([H1 | [H2|T] ]) ->
	[H1| rem_adj_dupl([H2| T])].

mem(_X,[]) ->
	false;
mem(X, [H|T]) -> X==H or mem(X,T).
