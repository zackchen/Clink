package com.feature.protoparser;

import clink.proto.Operations.Transform;

public class ToVectorBuilder extends BaseOperatorBuilder {

    private final Transform.Builder defaultBuilder = Transform.newBuilder();

    public ToVectorBuilder(String formula) {
        super(String.format("TO_VECTOR(%s)", formula));
    }
}
