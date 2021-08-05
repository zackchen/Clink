package com.feature.protoparser;

import libfg.proto.Operations.Transform;

public class KeepBuilder extends BaseOperatorBuilder {

    private final Transform.Builder defaultBuilder = Transform.newBuilder();

    public KeepBuilder(String formula) {
        super(String.format("KEEP(%s)", formula));
    }
}