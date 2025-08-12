/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:23:05 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/12 20:39:24 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A: [40, -3, 7, 15, 0]
// Ordenado: [-3, 0, 7, 15, 40]
// Índices:  [ 0, 1, 2,  3,  4]
// A indexada: [4, 0, 2, 3, 1]

// Repete tamanho de A vezes:
//     pega o 1º elemento
//     se bit i = 0 → pb
//     se bit i = 1 → ra
// Depois: pa até B ficar vazio

// Resumo mental:
//     Indexa os números.
//     Calcula quantos bits o maior valor tem.
//     Para cada bit:
//         0 → pb
//         1 → ra
//     Devolve B → A (pa).
//     Repetir até acabar os bits.

// 1. Descobre maior número → quantos dígitos/bits vou olhar.
// 2. Para cada dígito/bit:
	// a) Separa conforme valor do dígito/bit.
	// b) Junta de novo mantendo ordem.
// 3. Repete até passar por todos os dígitos/bits.